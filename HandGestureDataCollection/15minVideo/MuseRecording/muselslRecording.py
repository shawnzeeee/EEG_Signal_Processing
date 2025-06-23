#this is not complete, testing on the MuseStreamingTest.py

import subprocess
import time
import csv
from pylsl import StreamInlet, resolve_streams
import os
import mmap
import struct

subject = 'Shawn'
session = 6

SHARED_MEMORY_NAME = "Local\\GestureSharedMemory"
SHARED_MEMORY_SIZE = 256
shm = mmap.mmap(-1, SHARED_MEMORY_SIZE, SHARED_MEMORY_NAME, access=mmap.ACCESS_READ)

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

def read_gesture_classification(previous_gesture_code):
    #shm = mmap.mmap(-1, SHARED_MEMORY_SIZE, SHARED_MEMORY_NAME, access=mmap.ACCESS_READ)
    shm.seek(0)
    gesture_code = struct.unpack('i', shm.read(4))[0]
    #shm.close()
    if gesture_code != previous_gesture_code:
        return gesture_code
    return 0


def main():
    previous_gesture_code = 0

    print("[INFO] Press Ctrl+C to stop program.")

    # Prepare CSV file for writing
    script_dir = os.path.dirname(os.path.abspath(__file__))
    csv_filename = os.path.join(script_dir, f"muse_stream_.csv")
    print(f"[INFO] Saving CSV to: {csv_filename}")
    with open(csv_filename, mode='w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(["Channel 1", "Channel 2", "Channel 3", "Channel 4", "Class", "Row Number", "Session", "Subject"])
        row_number = 0

        # Step 1: Start Muse stream
        stream_proc = start_muse_stream()
        time.sleep(5)  # Give it time to initialize
        
        try:
            wait_for_stream(timeout=10)
            # Step 2: Connect to EEG stream
            inlet = connect_to_eeg_stream()

            # Step 3: Continuously read samples
            print("[INFO] Streaming EEG data...")
            while True:
                sample, timestamp = inlet.pull_sample()
                # Only take the first 4 channels
                shm.seek(0)
                gesture_code = struct.unpack('i', shm.read(4))[0]
                gesture_class = 0
                if gesture_code != previous_gesture_code:
                    gesture_class = gesture_code

                previous_gesture_code = gesture_code
                row = [sample[0], sample[1], sample[2], sample[3], gesture_class, row_number, session, subject]
                writer.writerow(row)
                row_number += 1
                # Optionally print or process_sample(sample, timestamp) if needed
        except KeyboardInterrupt:
            print("\n[INFO] Stopping...")
        finally:
            stream_proc.terminate()
            stream_proc.wait()
            print("[INFO] Muse stream terminated.")

if __name__ == "__main__":
    main()
