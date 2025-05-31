import pandas as pd
import numpy as np
from scipy.signal import welch

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
df = pd.read_csv("C:\\Users\\shawn_hx71ej8\\EEG_Signal_Processing\\Filter\\combined_data.csv")

# Rename columns to numbers
df.columns = range(df.shape[1])

# Separate class 0 (idle) and non-class 0 (active)
idle_df = df.iloc[:135000]  # First 135,000 rows are class 0
active_df = df.iloc[135000:]  # Remaining rows are non-class 0

# Prepare the output data
output_data = []

# Function to process windows and extract features
def process_windows(data, label, num_windows):
    processed_data = []
    for i in range(num_windows):
        start_idx = i * 500
        end_idx = start_idx + 500
        if end_idx > len(data):
            break
        window = data.iloc[start_idx:end_idx]

        # Extract features for each channel
        features = []
        for channel in range(4):  # Channels are numbered 0, 1, 2, 3
            signal = window[channel].values
            mobility, complexity = calculate_hjorth_parameters(signal)
            alpha_power, beta_power = calculate_bandpowers(signal)
            rms = calculate_rms(signal)
            features.extend([mobility, complexity, alpha_power, beta_power, rms])

        # Add the class label
        features.append(label)
        processed_data.append(features)
    return processed_data

# Process class 0 (idle state)
num_idle_windows = len(idle_df) // 500  # Number of 2-second windows for class 0
output_data.extend(process_windows(idle_df, 0, num_idle_windows))

# Process class 1 (active state) with the same number of windows as class 0
output_data.extend(process_windows(active_df, 1, num_idle_windows))

# Create a DataFrame for the output data
columns = [
    "Ch1_Mobility", "Ch1_Complexity", "Ch1_Alpha", "Ch1_Beta", "Ch1_RMS",
    "Ch2_Mobility", "Ch2_Complexity", "Ch2_Alpha", "Ch2_Beta", "Ch2_RMS",
    "Ch3_Mobility", "Ch3_Complexity", "Ch3_Alpha", "Ch3_Beta", "Ch3_RMS",
    "Ch4_Mobility", "Ch4_Complexity", "Ch4_Alpha", "Ch4_Beta", "Ch4_RMS",
    "Class"
]
output_df = pd.DataFrame(output_data, columns=columns)

# Save the output to a CSV file
output_df.to_csv("processed_features.csv", index=False)