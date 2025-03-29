import numpy as np
from scipy.signal import welch
from scipy.integrate import simps

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
