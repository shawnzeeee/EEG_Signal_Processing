import pandas as pd
import numpy as np
from scipy.signal import welch
import os

# Function to calculate RMS
def calculate_rms(signal):
    return np.sqrt(np.mean(signal**2))

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

# Load the CSV file
#df = pd.read_csv("C:\\Users\\shawn_hx71ej8\\EEG_Signal_Processing\\Filter\\combined_data.csv")
df = pd.read_csv("C:\\Users\\shawn\\EEG_Signal_Processing\\EEG_Recordings\\440\\Shawn\\4 channels\\30 sec break\\combined_data.csv")
# Rename columns to numbers
df.columns = range(df.shape[1])



# Separate class 0 (idle) and non-class 0 (active)
#idle_candidates = df.iloc[:135000]
#idle_indices = idle_candidates.sample(n=min(200, len(idle_candidates)), random_state=42).index

# Select rows beyond 135000, with non-zero class, shuffle, and match size to idle_indices
idle_indices = df.index[df[4] == 16]
active_indices = df.index[(df[4] != 0) & (df[4] != 16)]
#active_indices = active_candidates.sample(n=len(idle_indices), random_state=42).index


# Prepare the output data
output_data = []

# Function to process windows and extract features
def process_active_windows(center_indices, df, window_size=500):
    processed_data = []
    half_window = window_size // 2
    for idx in center_indices:
        start_idx = idx - half_window
        end_idx = idx + half_window
        # Ensure window is within bounds
        if start_idx < 0 or end_idx > len(df):
            continue
        window = df.iloc[start_idx:end_idx]
        features = []
        for channel in range(4):  # Channels are numbered 0, 1, 2, 3
            signal = window[channel].values
            mobility, complexity = calculate_hjorth_parameters(signal)
            alpha_power, beta_power = calculate_bandpowers(signal)
            rms = calculate_rms(signal)
            features.extend([mobility, complexity, alpha_power, beta_power, rms])
        actual_class = df.iloc[idx, 4]
        session = df.iloc[idx, 6]
        name = df.iloc[idx, 7]
        features.append(actual_class)  # Class
        features.append(1)  # Active
        features.append(session)
        features.append(name)
        processed_data.append(features)
    return processed_data

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
                rms = calculate_rms(signal)
                features.extend([mobility, complexity, alpha_power, beta_power, rms])
            actual_class = df.iloc[window_start, 4]
            session = df.iloc[window_start, 6]
            name = df.iloc[window_start, 7]
            features.append(0)  # Class
            features.append(0)  # Active
            features.append(session)
            features.append(name)
            processed_data.append(features)
    return processed_data

# Now, use the indices from idle_df and active_df as center points


output_data = []
output_data.extend(process_idle_windows(idle_indices, df))
output_data.extend(process_active_windows(active_indices, df))
# Create a DataFrame for the output data
columns = [
    "Ch1_Mobility", "Ch1_Complexity", "Ch1_Alpha", "Ch1_Beta", "Ch1_RMS",
    "Ch2_Mobility", "Ch2_Complexity", "Ch2_Alpha", "Ch2_Beta", "Ch2_RMS",
    "Ch3_Mobility", "Ch3_Complexity", "Ch3_Alpha", "Ch3_Beta", "Ch3_RMS",
    "Ch4_Mobility", "Ch4_Complexity", "Ch4_Alpha", "Ch4_Beta", "Ch4_RMS",
    "Class", "Active", "Session", "Name"
]
output_df = pd.DataFrame(output_data, columns=columns)

# Save the output to a CSV file
output_df.to_csv("processed_features.csv", index=False)