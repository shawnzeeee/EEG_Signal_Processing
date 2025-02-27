import numpy as np
import serial
from picard import picard
from mne import create_info
from mne.io import RawArray
import matplotlib.pyplot as plt

import 


# EEG parameters
sfreq = 250  # Sampling rate (Hz)
n_channels = 4  # Number of EEG channels
buffer_size = sfreq * 2  # 2 seconds of data

# Create EEG buffer
eeg_buffer = np.zeros((n_channels, buffer_size))

# Define MNE metadata
ch_names = ['C3', 'Cz', 'C4', 'Ref']
ch_types = ['eeg'] * n_channels
info = create_info(ch_names, sfreq, ch_types)

# Open USB Serial Connection (adjust COM port)
ser = serial.Serial('COM3', baudrate=115200, timeout=1)

def detect_eye_blink(components):
    """
    Identify and remove eye blink artifacts based on component power in low frequencies.
    """
    power = np.var(components, axis=0)  # Compute power of each component
    blink_component = np.argmax(power)  # Assume highest power corresponds to blinks
    components[:, blink_component] = 0  # Remove blink component
    return components

def process_realtime_ica():
    global eeg_buffer
    while True:
        try:
            # Read new EEG data
            line = ser.readline().decode('utf-8').strip()
            eeg_values = list(map(float, line.split(',')))
            
            if len(eeg_values) == n_channels:
                # Shift buffer (remove oldest, add new EEG sample)
                eeg_buffer = np.roll(eeg_buffer, -1, axis=1)
                eeg_buffer[:, -1] = eeg_values
                
                # Apply ICA on the buffered data
                components, W = picard(eeg_buffer.T, ortho=True)
                
                # Detect and remove eye blink artifacts
                components = detect_eye_blink(components)
                
                # Reconstruct cleaned EEG
                eeg_cleaned = np.dot(W.T, components.T)
                
                # Convert to MNE format and visualize
                raw = RawArray(eeg_cleaned, info)
                raw.plot(scalings='auto', show=True)
        except Exception as e:
            print(f"Error: {e}")
            continue  # Ignore errors and continue streaming

# Run real-time ICA processing
process_realtime_ica()
