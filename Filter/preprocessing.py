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
#df = pd.read_csv("C:\\Users\\shawn_hx71ej8\\EEG_Signal_Processing\\Filter\\combined_data.csv")
df = pd.read_csv("C:\\Users\\shawn\\EEG_Signal_Processing\\Filter\\combined_data.csv")
# Rename columns to numbers
df.columns = range(df.shape[1])



# Separate class 0 (idle) and non-class 0 (active)
idle_candidates = df.iloc[:135000]
idle_indices = idle_candidates.sample(n=min(200, len(idle_candidates)), random_state=42).index

# Select rows beyond 135000, with non-zero class, shuffle, and match size to idle_indices
active_candidates = df.iloc[135000:]
active_candidates = active_candidates[active_candidates[4] != 0]
active_indices = active_candidates.sample(n=len(idle_indices), random_state=42).index


# Prepare the output data
output_data = []

# Function to process windows and extract features
def process_windows(center_indices, label, df, window_size=500):
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
        features.append(label)
        #features.append(df.iloc[idx, 4])
        processed_data.append(features)
    return processed_data

# Now, use the indices from idle_df and active_df as center points


output_data = []
output_data.extend(process_windows(idle_indices, 0, df))
output_data.extend(process_windows(active_indices, 1, df))
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