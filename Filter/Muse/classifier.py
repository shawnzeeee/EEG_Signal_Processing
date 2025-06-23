import numpy as np
import time
import os
from scipy.signal import welch

# Function to calculate mobility and complexity (Hjorth parameters)
def calculate_hjorth_parameters(signal):
    first_derivative = np.diff(signal)
    second_derivative = np.diff(first_derivative)
    variance = np.var(signal)
    mobility = np.sqrt(np.var(first_derivative) / variance)
    complexity = np.sqrt(np.var(second_derivative) / np.var(first_derivative)) / mobility
    return mobility, complexity

# Function to calculate bandpowers (alpha and beta)
def calculate_bandpowers(signal, fs=250):
    freqs, psd = welch(signal, fs=fs, nperseg=fs)
    alpha_band = np.logical_and(freqs >= 8, freqs <= 13)
    beta_band = np.logical_and(freqs >= 13, freqs <= 30)
    alpha_power = np.sum(psd[alpha_band])
    beta_power = np.sum(psd[beta_band])
    return alpha_power, beta_power

def process_idle_windows(idle_indices, df, window_size=500, num_windows=15):
    processed_data = []
    for start_idx in idle_indices:
        for w in range(num_windows):
            window_start = start_idx + w * window_size
            window_end = window_start + window_size
            # Ensure window is within bounds
            if window_end > len(df):
                continue
            window = df.iloc[window_start:window_end]
            features = []
            for channel in range(4):  # Channels 0, 1, 2, 3
                signal = window[channel].values
                mobility, complexity = calculate_hjorth_parameters(signal)
                alpha_power, beta_power = calculate_bandpowers(signal)
                features.extend([mobility, complexity, alpha_power, beta_power])
            actual_class = df.iloc[window_start, 4]

            features.append(actual_class)  # Class

            processed_data.append(features)
    return processed_data

def process_attention_windows(center_indices, df, window_size=500, offset=500, num_windows=2):
    processed_data = []
    half_window = window_size // 2
    for idx in center_indices:
        for n in range(num_windows):
            attn_idx = idx + offset * (n + 1)
            start_idx = attn_idx - half_window
            end_idx = attn_idx + half_window
            if start_idx < 0 or end_idx > len(df):
                continue
            window = df.iloc[start_idx:end_idx]
            features = []
            for channel in range(4):
                signal = window[channel].values
                mobility, complexity = calculate_hjorth_parameters(signal)
                alpha_power, beta_power = calculate_bandpowers(signal)
                features.extend([mobility, complexity, alpha_power, beta_power])
            actual_class = df.iloc[idx, 4]
            features.append(actual_class)  # Class
            processed_data.append(features)
    return processed_data

file_path = os.path.join(os.path.dirname(__file__), 'data.bin')

print('[INFO] Reading EEG data from data.bin...')

window_size = 2000  # 2 seconds, 4 channels, 250Hz

try:
    while True:
        data_array = np.fromfile(file_path, dtype=np.float32)
        if len(data_array) < window_size:
            time.sleep(0.1)
            continue
        # Process all complete windows in the file
        for i in range(0, len(data_array) - window_size + 1, window_size):
            eeg_window = data_array[i:i+window_size].reshape(500, 4)
            #print("EEG Window (500 samples x 4 channels):\n", eeg_window)
        time.sleep(0.5)
except KeyboardInterrupt:
    print("Exiting...")