import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from numpy.fft import rfft, rfftfreq
from scipy.signal import welch
from scipy.stats import sem, t

file_path = "EEG_Recordings/440/Nick/4 channels/trial3.bin"
#file_path = "EEG_Recordings/440/Shawn/4 channels/30 sec break/trial_2_S.bin"
#file_path = "EEG_Recordings/440/Nick/4 channels/trial3.bin"
# Load the binary file and read as float32
data_array = np.fromfile(file_path, dtype=np.float32)

# Ensure data size is a multiple of 6 (each set: 4 channel readings + class + timestamp)
trimmed_size = (data_array.size // 6) * 6
trimmed_data = data_array[:trimmed_size]

# Reshape into 6 columns: [Channel1, Channel2, Channel3, Channel4, Class, Timestamp]
reshaped_data = trimmed_data.reshape(-1, 6)
#print(reshaped_data)

# Save reshaped data to CSV file
csv_filename = "reshaped_data.csv"
df = pd.DataFrame(reshaped_data, columns=["Channel 1", "Channel 2", "Channel 3", "Channel 4", "Class", "Timestamp"])
df.columns = range(df.shape[1])

# Only use the first 4 columns for EEG channel data, starting at row 1000
channels = df.iloc[1000:, 0:4].apply(pd.to_numeric, errors='coerce')
channels = channels.dropna()

# Rename columns to numbers
df.columns = range(df.shape[1])

idle_indices = df.index[(df.index >= 1000) & (df[4] == 16)]
# Find all non-zero classification indices (actions)
action_indices = df.index[(df.index >= 1000) & (df[4] != 0) & (df[4] != 16)]


fs = 250  # Sampling frequency (Hz), adjust if different
nperseg = fs  # 1 second window for Welch

window_size = 500
half_window = window_size // 2

colors = plt.rcParams['axes.prop_cycle'].by_key()['color']

current_action = [0]  # Use a mutable type so it can be changed in the event handler

fig, axs = plt.subplots(4, 1, figsize=(12, 20), sharex=True)
lines = []

# Find the first occurrence of class 16 (break period) safely
break_indices = df.index[df[4] == 16]
if len(break_indices) == 0:
    raise ValueError("No break period (class 16) found in the data. Cannot set baseline.")
baseline_start = break_indices[0]
baseline_end = baseline_start + 30 * fs  # 30 seconds baseline

def get_baseline_spectra():
    baseline_channels = df.iloc[baseline_start:baseline_end, 0:4].apply(pd.to_numeric, errors='coerce').fillna(0)
    spectra = []
    for ch in range(4):
        signal = baseline_channels.iloc[:, ch].values
        freqs, psd = welch(signal, fs=fs, nperseg=nperseg)
        spectra.append((freqs, psd))
    return spectra

def get_psd_and_ci(signals, fs, nperseg, alpha=0.05):
    n = signals.shape[0]
    psds = []
    cis = []
    for ch in range(signals.shape[1]):
        freqs, psd = welch(signals[:, ch], fs=fs, nperseg=nperseg)
        psds.append(psd)
        sem_psd = np.zeros_like(psd)  # Welch returns mean, so SEM is 0 (approximation)
        ci = t.ppf(1 - alpha/2, n-1) * sem_psd
        cis.append(ci)
    return freqs, np.array(psds), np.array(cis)

def plot_action(idx):
    for ax in axs:
        ax.clear()
    action_idx = action_indices[idx]
    # Baseline window
    baseline_channels = df.iloc[baseline_start:baseline_end, 0:4].apply(pd.to_numeric, errors='coerce').fillna(0).values
    freqs, baseline_psds, baseline_cis = get_psd_and_ci(baseline_channels, fs, nperseg)
    # Action window
    start_idx = max(0, action_idx - half_window)
    end_idx = start_idx + window_size
    if end_idx > len(df):
        end_idx = len(df)
        start_idx = end_idx - window_size
    action_channels = df.iloc[start_idx:end_idx, 0:4].apply(pd.to_numeric, errors='coerce').fillna(0).values
    freqs_win, action_psds, action_cis = get_psd_and_ci(action_channels, fs, nperseg)
    # Only plot frequencies from 7 to 15 Hz
    freq_mask = (freqs >= 7) & (freqs <= 15)
    freq_mask_win = (freqs_win >= 7) & (freqs_win <= 15)
    for ch in range(4):
        # Baseline
        axs[ch].plot(freqs[freq_mask], baseline_psds[ch][freq_mask], label='Baseline', color=colors[ch])
        axs[ch].fill_between(freqs[freq_mask], baseline_psds[ch][freq_mask] - baseline_cis[ch][freq_mask], baseline_psds[ch][freq_mask] + baseline_cis[ch][freq_mask], color=colors[ch], alpha=0.2, label='Baseline 95% CI')
        # Action
        axs[ch].plot(freqs_win[freq_mask_win], action_psds[ch][freq_mask_win], linestyle=':', color=colors[ch], label='Action Window')
        axs[ch].fill_between(freqs_win[freq_mask_win], action_psds[ch][freq_mask_win] - action_cis[ch][freq_mask_win], action_psds[ch][freq_mask_win] + action_cis[ch][freq_mask_win], color=colors[ch], alpha=0.2, linestyle=':', label='Action 95% CI')
        axs[ch].set_xlim(7, 15)
        axs[ch].set_ylabel('Power Spectral Density')
        axs[ch].set_title(f'Channel {ch+1} | Action {idx+1}/{len(action_indices)}, Index={action_idx}, Class={df.iloc[action_idx, 4]}')
        axs[ch].legend()
    axs[-1].set_xlabel('Frequency (Hz)')
    plt.tight_layout()
    plt.draw()

plot_action(current_action[0])

# Key event handler
def on_key(event):
    if event.key == 'right':
        if current_action[0] < len(action_indices) - 1:
            current_action[0] += 1
            plot_action(current_action[0])
    elif event.key == 'left':
        if current_action[0] > 0:
            current_action[0] -= 1
            plot_action(current_action[0])

fig.canvas.mpl_connect('key_press_event', on_key)
plt.show()
