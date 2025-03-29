import numpy as np
from scipy.signal import welch
from scipy.integrate import simps

# Define the file path again
file_path = "EEG_Recordings/Nick/gabeInterruptedMe.bin"

# Load the binary file and read as float32
data_array = np.fromfile(file_path, dtype=np.float32)

# Ensure data size is a multiple of 6 (each set: 4 channel readings + class + timestamp)
trimmed_size = (data_array.size // 6) * 6
trimmed_data = data_array[:trimmed_size]

# Reshape into 6 columns: [Channel1, Channel2, Channel3, Channel4, Class, Timestamp]
reshaped_data = trimmed_data.reshape(-1, 6)

Xfeat1 = extract_eeg_features(reshaped_data[500:15000, 1],250)
Xfeat2 = extract_eeg_features(reshaped_data[500:15000, 2],250)
Xfeat3 = extract_eeg_features(reshaped_data[500:15000, 3],250)
Xfeat4 = extract_eeg_features(reshaped_data[500:15000, 4],250)

Xfeatures = [Xfeat1; Xfeat2; Xfeat3; Xfeat4]';

def bandpower(data, fs, band, method='welch'):
    low, high = band
    freqs, psd = welch(data, fs=fs)
    # Find index of band range
    idx_band = np.logical_and(freqs >= low, freqs <= high)
    band_power = simps(psd[idx_band], freqs[idx_band])
    return band_power

def extract_eeg_features(eeg_signal, fs):
    eeg_signal = np.asarray(eeg_signal)

    # Power in Alpha and Beta Bands
    alpha_power = bandpower(eeg_signal, fs, [8, 13])
    beta_power = bandpower(eeg_signal, fs, [13, 30])
    
    # RMS
    rms_value = np.sqrt(np.mean(eeg_signal**2))
    
    # Hjorth Parameters
    diff1 = np.diff(eeg_signal)
    diff2 = np.diff(diff1)
    mobility = np.std(diff1) / np.std(eeg_signal)
    complexity = np.std(diff2) / np.std(diff1)
    
    # Combine features into a vector
    features = np.array([alpha_power, beta_power, rms_value, mobility, complexity])
    return features
