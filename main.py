import serial
import numpy as np
import mne
from mne import create_info
from mne.io import RawArray
from picard import picard
import matplotlib.pyplot as plt

# Define EEG Parameters
sfreq = 250  # Sampling rate (adjust for your EEG device)
n_channels = 4  # Number of EEG channels
ch_names = ['C3', 'Cz', 'C4', 'Ref']  # Replace with your actual electrode names
ch_types = ['eeg'] * n_channels

# Create MNE info object
info = create_info(ch_names, sfreq, ch_types)

# Initialize EEG buffer
buffer_size = sfreq * 2  # Store 2 seconds of data
eeg_buffer = np.zeros((n_channels, buffer_size))

# Open USB Serial Connection
ser = serial.Serial('COM3', baudrate=115200, timeout=1)

def update_eeg_data():
    global eeg_buffer
    while True:
        try:
            line = ser.readline().decode('utf-8').strip()
            eeg_values = list(map(float, line.split(',')))  # Convert string to float list
            
            if len(eeg_values) == n_channels:
                eeg_buffer = np.roll(eeg_buffer, -1, axis=1)  # Shift data left
                eeg_buffer[:, -1] = eeg_values  # Add new EEG data
                
                # Apply Picard ICA (Fast ICA Alternative)
                components, W = picard(eeg_buffer.T, ortho=True)
                
                # Convert back to EEG format
                eeg_cleaned = np.dot(W.T, components.T)
                
                # Convert EEG buffer to MNE RawArray
                raw = RawArray(eeg_cleaned, info)
                raw.plot(scalings='auto', show=True)  # Live EEG Plot
        except Exception as e:
            print(f"Error: {e}")
            continue  # Ignore bad data packets

# Run the EEG Streaming
update_eeg_data()
