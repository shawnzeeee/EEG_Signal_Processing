import subprocess
import os
import sys
import time

# Get the directory containing this script
script_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.dirname(script_dir)

# Paths to the scripts
muselsl_script = os.path.join(script_dir, 'muselslRecording.py')
data_collection_script = os.path.join(script_dir, 'museDataCollection.py')

# Start museDataCollection.py (writer) first
print('[INFO] Starting museDataCollection.py...')
data_proc = subprocess.Popen(
    [sys.executable, data_collection_script],
    cwd=script_dir
)

# Wait to ensure shared memory is created
print('[INFO] Waiting for shared memory to be initialized...')
time.sleep(2)

# Start muselslRecording.py (reader)
print('[INFO] Starting muselslRecording.py...')
muse_proc = subprocess.Popen(
    [sys.executable, muselsl_script],
    cwd=script_dir
)

# Wait a few seconds to ensure EEG stream is ready
print('[INFO] Waiting for Muse stream to initialize...')
time.sleep(5)


try:
    # Wait for both processes to finish
    muse_proc.wait()
    data_proc.wait()
except KeyboardInterrupt:
    print('\n[INFO] Stopping both processes...')
    muse_proc.terminate()
    data_proc.terminate()
    muse_proc.wait()
    data_proc.wait()
    print('[INFO] Both processes terminated.')
