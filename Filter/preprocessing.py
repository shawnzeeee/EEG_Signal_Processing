import pandas as pd
import numpy as np
from scipy.signal import welch
import os
import glob

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

# Directory containing the trial CSV files
trial_dir = "C:/Users/shawn/EEG_Signal_Processing/EEG_Recordings/440/Muse/Shawn New"
all_files = glob.glob(os.path.join(trial_dir, "trial_*.csv"))

all_output_data = []

for file_path in all_files:
    # Extract session number from filename
    base = os.path.basename(file_path)
    session_number = int(base.split('_')[1].split('.')[0])
    df = pd.read_csv(file_path)
    df.columns = range(df.shape[1])
    idle_indices = df.index[df[4] == 15]
    active_indices = df.index[(df[4] != 0) & (df[4] != 15)]

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
            name = df.iloc[idx, 7] if df.shape[1] > 7 else "Unknown"
            features.append(actual_class)  # Class
            features.append(1)  # Active
            features.append(session_number)
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
                name = df.iloc[window_start, 7] if df.shape[1] > 7 else "Unknown"
                features.append(0)  # Class
                features.append(0)  # Active
                features.append(session_number)
                features.append(name)
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
                    rms = calculate_rms(signal)
                    features.extend([mobility, complexity, alpha_power, beta_power, rms])
                actual_class = df.iloc[idx, 4]
                name = df.iloc[idx, 7] if df.shape[1] > 7 else "Unknown"
                features.append(16)  # Class
                features.append(2)  # Attention window
                features.append(session_number)
                features.append(name)
                processed_data.append(features)
        return processed_data

    def process_premotor_windows(center_indices, df, window_size=500, gap=250):
        processed_data = []
        half_window = window_size // 2
        for idx in center_indices:
            # Premotor window ends 1 second (gap) before the active window center
            premotor_center = idx - (window_size // 2) - gap
            start_idx = premotor_center - half_window
            end_idx = premotor_center + half_window
            if start_idx < 0 or end_idx > len(df):
                continue
            window = df.iloc[start_idx:end_idx]
            features = []
            for channel in range(4):
                signal = window[channel].values
                mobility, complexity = calculate_hjorth_parameters(signal)
                alpha_power, beta_power = calculate_bandpowers(signal)
                rms = calculate_rms(signal)
                features.extend([mobility, complexity, alpha_power, beta_power, rms])
            actual_class = df.iloc[idx, 4]  # Use the class at the active window center
            name = df.iloc[idx, 7] if df.shape[1] > 7 else "Unknown"
            features.append(17)  # Class 17 for premotor
            features.append(3)   # 3 for premotor window
            features.append(session_number)
            features.append(name)
            processed_data.append(features)
        return processed_data

    all_output_data.extend(process_idle_windows(idle_indices, df))
    all_output_data.extend(process_active_windows(active_indices, df))
    all_output_data.extend(process_attention_windows(active_indices, df))
    all_output_data.extend(process_premotor_windows(active_indices, df))

columns = [
    "Ch1_Mobility", "Ch1_Complexity", "Ch1_Alpha", "Ch1_Beta", "Ch1_RMS",
    "Ch2_Mobility", "Ch2_Complexity", "Ch2_Alpha", "Ch2_Beta", "Ch2_RMS",
    "Ch3_Mobility", "Ch3_Complexity", "Ch3_Alpha", "Ch3_Beta", "Ch3_RMS",
    "Ch4_Mobility", "Ch4_Complexity", "Ch4_Alpha", "Ch4_Beta", "Ch4_RMS",
    "Class", "Active", "Session", "Name"
]
output_df = pd.DataFrame(all_output_data, columns=columns)
output_df.to_csv("processed_features.csv", index=False)