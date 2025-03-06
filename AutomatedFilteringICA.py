import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import FastICA
from scipy.stats import pearsonr, kurtosis
import time

# Load CSV file
file_path = "Data/EOG_dataset.csv"  # Replace with your actual file path
columns_to_read = ["Channel_0", "Channel_1", "Channel_3"]  # Replace with actual column names
data = pd.read_csv(file_path, usecols=columns_to_read)

# Ensure the data is numerical
numerical_data = data.select_dtypes(include=[np.number]).dropna()

# Compute ICA on blink region (rows 797 to 897)
blink_window = numerical_data.iloc[1221:1321]
n_components = min(3, numerical_data.shape[1])  # Ensure we don't exceed dimensions
ica_blink = FastICA(n_components=n_components, random_state=42)
blink_components = ica_blink.fit_transform(blink_window)

# Plot blink-related ICA components
plt.figure(figsize=(10, 6))
for i in range(n_components):
    plt.plot(blink_components[:, i], linewidth=0.8, label=f'Blink Component {i + 1}')
plt.title("Blink-Related ICA Components (Rows 797-897)")
plt.xlabel("Sample")
plt.ylabel("Amplitude")
plt.legend()
plt.show()

# Compute ICA on the entire dataset
n_components = min(3, numerical_data.shape[1])  # Ensure we don't exceed dimensions
ica = FastICA(n_components=n_components, random_state=42)
components = ica.fit_transform(numerical_data)

# Moving window parameters
window_size = 100  # Number of rows per window
step_size = 20  # Overlapping step size

# Storage for final reconstructed signal
final_reconstructed_signal = np.zeros_like(numerical_data)
count_matrix = np.zeros_like(numerical_data)  # To track contributions for averaging

# Set up real-time plot
plt.ion()
fig, ax = plt.subplots(figsize=(10, 6))
lines = [ax.plot([], [], linewidth=0.8, label=f'Reconstructed Channel {i + 1}')[0] for i in range(final_reconstructed_signal.shape[1])]
ax.set_xlim(0, numerical_data.shape[0])
ax.set_ylim(np.min(numerical_data.values), np.max(numerical_data.values))
ax.set_title("Real-Time Reconstructed EEG Signal")
ax.set_xlabel("Sample")
ax.set_ylabel("Amplitude")
ax.legend()


for start in range(0, numerical_data.shape[0] - window_size, step_size):
    window_data = numerical_data.iloc[start:start + window_size]
    
    ica_window = FastICA(n_components=n_components, random_state=42, whiten='unit-variance')
    window_components = ica_window.fit_transform(window_data)
    
    # Identify components to remove based on peak amplitude
    components_to_remove = []
    for i in range(n_components):
        corr, _ = pearsonr(blink_components[:window_components.shape[0], 1], window_components[:, i])
        if  abs(corr) > 0.1:
            components_to_remove.append(i)
    
    # Remove flagged components
    filtered_components = window_components.copy()
    for comp in components_to_remove:
        filtered_components[:, comp] = 0  # Zero out the identified component
    #filtered_components[:, 1] = 0
    # Reconstruct the filtered signal
    reconstructed_signal = ica_window.inverse_transform(filtered_components)
    
    # Append to final reconstructed signal using step size to avoid redundancy
    final_reconstructed_signal[start:start + step_size] += reconstructed_signal[-step_size:]
    count_matrix[start:start + step_size] += 1
    # Update real-time plot
    for i, line in enumerate(lines):
        line.set_data(np.arange(final_reconstructed_signal.shape[0]), final_reconstructed_signal[:, i])
    ax.relim()
    ax.autoscale_view()
    plt.draw()
    plt.pause(0.01)  # Small pause to update the figure in real-time

# Normalize the final signal by dividing by count matrix to average overlapping values
final_reconstructed_signal[count_matrix > 0] /= count_matrix[count_matrix > 0]

# Plot the final reconstructed EEG signal
plt.figure(figsize=(10, 6))
for i in range(final_reconstructed_signal.shape[1]):
    plt.plot(final_reconstructed_signal[:, i], linewidth=0.8, label=f'Reconstructed Channel {i + 1}')
plt.title("Final Reconstructed EEG Signal")
plt.xlabel("Sample")
plt.ylabel("Amplitude")
plt.legend()
plt.show()

print("Moving window ICA processing complete.")
