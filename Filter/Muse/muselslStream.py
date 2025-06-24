#this is not complete, testing on the MuseStreamingTest.py

import subprocess
import time
import csv
from pylsl import StreamInlet, resolve_streams
import os
import mmap
import struct
import numpy as np

script_dir = os.path.dirname(os.path.abspath(__file__))

SHARED_MEMORY_NAME = "Local\\GestureSharedMemory"
SHARED_MEMORY_SIZE = 256
shm = mmap.mmap(-1, SHARED_MEMORY_SIZE, SHARED_MEMORY_NAME, access=mmap.ACCESS_WRITE)

subject = 'Shawn'
session = 6

def start_muse_stream():
    print("[INFO] Starting Muse stream...")
    # Start the stream in a background process
    return subprocess.Popen(["muselsl", "stream"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

def muse_connected():
    streams = resolve_streams()
    for stream in streams:
        if stream.type() == 'EEG' and 'Muse' in stream.name():
            print(f"[CONNECTED] Found stream: {stream.name()}")
            return True
    print("[NOT CONNECTED] No Muse EEG stream found.")
    return False

def wait_for_stream(timeout=10):
    print("[INFO] Waiting for EEG stream...")
    start_time = time.time()
    while time.time() - start_time < timeout:
        if muse_connected():
            return True
        time.sleep(1)
    raise TimeoutError("[ERROR] Timed out waiting for Muse EEG stream.")

def connect_to_eeg_stream():
    print("[INFO] Looking for an EEG stream...")
    streams = resolve_streams()
    if not streams:
        raise RuntimeError("[ERROR] No EEG stream found. Is Muse powered on?")
    print("[INFO] EEG stream found.")
    return StreamInlet(streams[0])

def process_sample(sample, timestamp):
    # Custom processing (replace with your own logic)
    print(f"Timestamp: {timestamp:.3f} | EEG: {sample}")



def main():
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--mode', choices=['calibration', 'stream'], default='stream', help='Mode: calibration or stream')
    args = parser.parse_args()

    buffer_size = 4 * 250 * 2  # 2000
    eeg_buffer = np.zeros(buffer_size, dtype=np.float32)
    buffer_ptr = 0
    row_number = 0
    
    previous_class = 0

    # Step 1: Start Muse stream
    stream_proc = start_muse_stream()
    time.sleep(5)  # Give it time to initialize

    if args.mode == 'calibration':
        # Calibration mode: write to CSV
        import csv
        csv_file_path = os.path.join(os.path.dirname(__file__), 'calibration.csv')
        csv_file = open(csv_file_path, 'w', newline='')
        writer = csv.writer(csv_file)
        writer.writerow(["Channel 1", "Channel 2", "Channel 3", "Channel 4", "Class"])
    else:
        # Stream mode: write to binary
        bin_file_path = os.path.join(os.path.dirname(__file__), 'data.bin')
        bin_file = open(bin_file_path, 'wb')

    try:
        wait_for_stream(timeout=10)
        inlet = connect_to_eeg_stream()
        print(f"[INFO] Streaming EEG data... Writing to {'calibration.csv' if args.mode == 'calibration' else 'data.bin'}")
        while True:
            sample, timestamp = inlet.pull_sample()
            if args.mode == 'calibration':
                # Read gesture class from shared memory
                shm.seek(0)
                classification = struct.unpack('i', shm.read(4))[0]
                send_code = 0
                if classification != previous_class:
                    send_code = classification
                row = [sample[0], sample[1], sample[2], sample[3], send_code]
                previous_class = classification
                writer.writerow(row)
                row_number += 1
            else:
                eeg_buffer[buffer_ptr:buffer_ptr+4] = sample[:4]
                buffer_ptr = (buffer_ptr + 4) % buffer_size
                if len(eeg_buffer) == buffer_size:
                    if np.all(np.isfinite(eeg_buffer)):
                        ordered_buffer = np.roll(eeg_buffer, -buffer_ptr)
                        bin_file.seek(0)  # Move to the start of the file

                        bin_file.write(ordered_buffer.tobytes())
                        bin_file.flush()
                    else:
                        print("[WARN] Buffer contains non-finite values. Skipping write.")
    except KeyboardInterrupt:
        print("\n[INFO] Stopping...")
    finally:
        if args.mode == 'calibration':
            csv_file.close()
        else:
            bin_file.close()
        stream_proc.terminate()
        stream_proc.wait()
        print("[INFO] Muse stream terminated.")

if __name__ == "__main__":
    main()
