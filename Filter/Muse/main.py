import subprocess
import sys
import os
import time

script_dir = os.path.dirname(os.path.abspath(__file__))

muselsl_stream_script = os.path.join(script_dir, 'muselslStream.py')
classifier_script = os.path.join(script_dir, 'classifier.py')
calibration_script = os.path.join(script_dir, 'calibration.py')

# Step 1: Start muselslStream.py in calibration mode
print('[INFO] Starting muselslStream.py in calibration mode...')
stream_proc = subprocess.Popen([sys.executable, muselsl_stream_script, '--mode', 'calibration'], cwd=script_dir)

# Wait a moment to ensure the stream is initialized and shared memory is available
print('[INFO] Waiting for stream to initialize...')
time.sleep(5)

# Step 2: Start calibration.py in parallel
print('[INFO] Starting calibration.py...')
calibration_proc = subprocess.Popen([sys.executable, calibration_script], cwd=script_dir)

try:
    # Wait for calibration.py to finish
    while calibration_proc.poll() is None:
        time.sleep(1)
except KeyboardInterrupt:
    print('\n[INFO] KeyboardInterrupt: Stopping calibration and muselslStream...')
    calibration_proc.terminate()
    stream_proc.terminate()
    calibration_proc.wait()
    stream_proc.wait()
    print('[INFO] Calibration and muselslStream terminated.')
    sys.exit(0)

# Step 3: Calibration done, terminate muselslStream.py (calibration mode)
print('[INFO] Calibration complete. Stopping muselslStream.py (calibration mode)...')
stream_proc.terminate()
stream_proc.wait()

# Step 4: Start muselslStream.py in stream mode
print('[INFO] Starting muselslStream.py in stream mode...')
stream_proc = subprocess.Popen([sys.executable, muselsl_stream_script, '--mode', 'stream'], cwd=script_dir)

# Wait a moment to ensure the stream is initialized
print('[INFO] Waiting for stream to initialize...')
time.sleep(5)

# Step 5: Start classifier.py in parallel
print('[INFO] Starting classifier.py...')
classifier_proc = subprocess.Popen([sys.executable, classifier_script], cwd=script_dir)

try:
    while True:
        if stream_proc.poll() is not None or classifier_proc.poll() is not None:
            break
        time.sleep(1)
except KeyboardInterrupt:
    print('\n[INFO] KeyboardInterrupt: Stopping both processes...')
    stream_proc.terminate()
    classifier_proc.terminate()
    stream_proc.wait()
    classifier_proc.wait()
    print('[INFO] Both processes terminated.')
    sys.exit(0)

print('[INFO] One of the processes exited. Cleaning up...')
stream_proc.terminate()
classifier_proc.terminate()
stream_proc.wait()
classifier_proc.wait()
print('[INFO] All processes terminated.')