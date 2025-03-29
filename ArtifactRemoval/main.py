import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.decomposition import FastICA

# Define the file path again
#file_path = "EEG_Recordings/Daniel/BaseRecording/trial1.bin"
file_path = "./EEG_Recordings/Shawn/1minOpenClose/trial5.bin"

# Load the binary file and read as float32
data_array = np.fromfile(file_path, dtype=np.float32)

start = 500
# Ensure data size is a multiple of 6 (each set: 4 channel readings + class + timestamp)
trimmed_size = (data_array.size // 6) * 6

trimmed_data = data_array[:trimmed_size]

# Reshape into 6 columns: [Channel1, Channel2, Channel3, Channel4, Class, Timestamp]
reshaped_data = trimmed_data.reshape(-1, 6)

# Extract the EEG channels (first 4 columns)
eeg_channels = reshaped_data[start:, :4]

class_labels = reshaped_data[start:, 4]  # Classification labels (11 for open, 12 for close)


# Find the first instance of a classification (11 or 12)
classification_indices = np.where((class_labels == 11) | (class_labels == 12))[0]
if len(classification_indices) > 0:
    first_classification_index = classification_indices[0]
else:
    raise ValueError("No classification labels (11 or 12) found in the data.")

# Define the window size (500 points) and calculate the start and end indices
window_size = 500
half_window = window_size // 2
start_index = max(0, first_classification_index - half_window)
end_index = start_index + window_size

# Ensure the window does not exceed the data bounds
if end_index > eeg_channels.shape[0]:
    end_index = eeg_channels.shape[0]
    start_index = end_index - window_size

# Extract the windowed data
windowed_eeg = eeg_channels[start_index:end_index, :]
windowed_labels = class_labels[start_index:end_index]

# Plot the windowed EEG channels with classification labels
fig, axes = plt.subplots(windowed_eeg.shape[1], 1, figsize=(12, 8), sharex=True)
fig.suptitle("Windowed EEG Channels with Classification Labels", fontsize=16)
for i in range(windowed_eeg.shape[1]):
    axes[i].plot(windowed_eeg[:, i], label=f'Channel {i+1}')
    axes[i].set_title(f"Channel {i+1}")
    axes[i].set_ylabel("Amplitude")
    axes[i].legend()
    # Overlay classification labels
    for j in range(len(windowed_labels)):
        if windowed_labels[j] == 11:  # Open hand
            axes[i].axvline(x=j, color='green', linestyle='--', alpha=0.5, label='Open Hand' if j == 0 else "")
        elif windowed_labels[j] == 12:  # Close hand
            axes[i].axvline(x=j, color='red', linestyle='--', alpha=0.5, label='Close Hand' if j == 0 else "")
axes[-1].set_xlabel("Samples")
axes[0].legend(loc='upper right')  # Add legend to the first subplot
plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.show()

# Apply FastICA to the windowed EEG data
ica = FastICA(n_components=windowed_eeg.shape[1], random_state=42)
ica_sources = ica.fit_transform(windowed_eeg)  # Independent components

ica_sources[:, 0] = 0  # Zero out the first component
ica_sources[:, 1] = 0  # Zero out the second component

# Reconstruct the signal using the modified ICA sources
reconstructed_signal = ica.inverse_transform(ica_sources)




# Plot the ICA components
fig, axes = plt.subplots(ica_sources.shape[1], 1, figsize=(12, 8), sharex=True)
fig.suptitle("ICA Components of Windowed EEG Data", fontsize=16)
for i in range(ica_sources.shape[1]):
    axes[i].plot(ica_sources[:, i], label=f'ICA Component {i+1}')
    axes[i].set_title(f"ICA Component {i+1}")
    axes[i].set_ylabel("Amplitude")
    axes[i].legend()
    # Overlay classification labels
    for j in range(len(windowed_labels)):
        if windowed_labels[j] == 11:  # Open hand
            axes[i].axvline(x=j, color='green', linestyle='--', alpha=0.5, label='Open Hand' if j == 0 else "")
        elif windowed_labels[j] == 12:  # Close hand
            axes[i].axvline(x=j, color='red', linestyle='--', alpha=0.5, label='Close Hand' if j == 0 else "")
axes[-1].set_xlabel("Samples")
axes[0].legend(loc='upper right')  # Add legend to the first subplot
plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.show()


# Plot the reconstructed signal
fig, axes = plt.subplots(reconstructed_signal.shape[1], 1, figsize=(12, 8), sharex=True)
fig.suptitle("Reconstructed EEG Signal (After Removing First and Third ICA Components)", fontsize=16)
for i in range(reconstructed_signal.shape[1]):
    axes[i].plot(reconstructed_signal[:, i], label=f'Reconstructed Channel {i+1}')
    axes[i].set_title(f"Reconstructed Channel {i+1}")
    axes[i].set_ylabel("Amplitude")
    axes[i].legend()
    # Overlay classification labels
    for j in range(len(windowed_labels)):
        if windowed_labels[j] == 11:  # Open hand
            axes[i].axvline(x=j, color='green', linestyle='--', alpha=0.5, label='Open Hand' if j == 0 else "")
        elif windowed_labels[j] == 12:  # Close hand
            axes[i].axvline(x=j, color='red', linestyle='--', alpha=0.5, label='Close Hand' if j == 0 else "")
axes[-1].set_xlabel("Samples")
axes[0].legend(loc='upper right')  # Add legend to the first subplot
plt.tight_layout(rect=[0, 0, 1, 0.96])
plt.show()

