import numpy as np
from scipy.signal import welch, windows
from scipy.stats import variation

def extract_eeg_features(eeg_signal, fs):
    """
    Extracts EEG features:
      - Alpha power (8-13 Hz)
      - Beta power (13-30 Hz)
      - RMS value
      - Hjorth mobility and complexity

    Parameters:
        eeg_signal (1D np.array): EEG signal
        fs (float): Sampling frequency in Hz

    Returns:
        features (1D np.array): [alpha_power, beta_power, rms, mobility, complexity]
    """
    window = windows.hamming(256)
    f, pxx = welch(eeg_signal, fs=fs, window=window, nperseg=256, noverlap=128, nfft=512)

    # Bandpower in alpha (8-13 Hz)
    alpha_band = (f >= 8) & (f <= 13)
    alpha_power = np.trapz(pxx[alpha_band], f[alpha_band])

    # Bandpower in beta (13-30 Hz)
    beta_band = (f >= 13) & (f <= 30)
    beta_power = np.trapz(pxx[beta_band], f[beta_band])

    # RMS
    rms_val = np.sqrt(np.mean(eeg_signal ** 2))

    # Hjorth Parameters
    first_deriv = np.diff(eeg_signal)
    second_deriv = np.diff(first_deriv)

    var0 = np.var(eeg_signal)
    var1 = np.var(first_deriv)
    var2 = np.var(second_deriv)

    mobility = np.sqrt(var1 / var0) if var0 != 0 else 0
    complexity = np.sqrt((var2 / var1) - (var1 / var0)) if var1 != 0 and var0 != 0 else 0

    return np.array([alpha_power, beta_power, rms_val, mobility, complexity])



# Define the file path again
file_path = "EEG_Recordings/Nick/singleHandClose/trial1.bin"

# Load the binary file and read as float32
data_array = np.fromfile(file_path, dtype=np.float32)

# Ensure data size is a multiple of 6 (each set: 4 channel readings + class + timestamp)
trimmed_size = (data_array.size // 6) * 6
trimmed_data = data_array[:trimmed_size]

# Reshape into 6 columns: [Channel1, Channel2, Channel3, Channel4, Class, Timestamp]
reshaped_data = trimmed_data.reshape(-1, 6)
sTime = 300
eTime = 2000

Xfeat1 = extract_eeg_features(reshaped_data[sTime:eTime, 1],250)
Xfeat2 = extract_eeg_features(reshaped_data[sTime:eTime, 2],250)
Xfeat3 = extract_eeg_features(reshaped_data[sTime:eTime, 3],250)
Xfeat4 = extract_eeg_features(reshaped_data[sTime:eTime, 4],250)
print(Xfeat1)
print(Xfeat2)
print(Xfeat3)
print(Xfeat4)

Xfeatures = np.vstack([Xfeat1, Xfeat2, Xfeat3, Xfeat4])
