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

# Extract multiple blink window ICA components (Component 2) for better alignment
blink_references = []
kurtosis_references = []
for start in range(1180, 1360, 20):  # Extract from 1180-1280 to 1260-1360 in steps of 20
    blink_window = numerical_data.iloc[start:start+100]
    ica_blink = FastICA(n_components=3, random_state=42)
    blink_components = ica_blink.fit_transform(blink_window)
    blink_references.append(blink_components[:, 1])  # Store Component 2
    kurtosis_references.append(kurtosis(blink_components[:, 1]))  # Store Kurtosis Value


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

plt.ion()
fig, ax = plt.subplots(figsize=(10, 6))

# Plot for original and reconstructed signal
#lines_original = [ax.plot([], [], linewidth=0.8, linestyle='dashed', label=f'Original Channel {i + 1}')[0] for i in range(numerical_data.shape[1])]
lines_reconstructed = [ax.plot([], [], linewidth=0.8, label=f'Reconstructed Channel {i + 1}')[0] for i in range(final_reconstructed_signal.shape[1])]
ax.set_xlim(0, numerical_data.shape[0])
ax.set_ylim(np.min(numerical_data.values), np.max(numerical_data.values))
ax.set_title("Real-Time EEG Signal: Original vs Reconstructed")
ax.set_xlabel("Sample")
ax.set_ylabel("Amplitude")
ax.legend()

# Process data in moving windows
for start in range(0, numerical_data.shape[0] - window_size, step_size):
    window_data = numerical_data.iloc[start:start + window_size]
    
    ica_window = FastICA(n_components=n_components, random_state=42, whiten='unit-variance')
    window_components = ica_window.fit_transform(window_data)
    
    # Identify components to remove based on correlation and kurtosis similarity
    components_to_remove = []
    for i in range(n_components):
        max_corr = max(abs(pearsonr(blink_ref[:window_components.shape[0]], window_components[:, i])[0]) for blink_ref in blink_references)
        kurtosis_value = kurtosis(window_components[:, i])
        
        # Compare to the best matching blink reference kurtosis
        min_kurtosis_diff = min(abs(kurtosis_value - blink_kurt) for blink_kurt in kurtosis_references)
        peak_value = np.max(np.abs(window_components[:, i]))
        if max_corr > 0.4:
            components_to_remove.append(i)
            print(f"Component {i+1} flagged for removal (Corr: {max_corr:.4f}, Kurtosis Diff: {min_kurtosis_diff:.4f}).")
    
    # Remove flagged components
    filtered_components = window_components.copy()
    for comp in components_to_remove:
        filtered_components[:, comp] = 0  # Zero out the identified component
    
    # Reconstruct the filtered signal
    reconstructed_signal = ica_window.inverse_transform(filtered_components)
    
    # Append to final reconstructed signal using step size to avoid redundancy
    final_reconstructed_signal[start:start + step_size] += reconstructed_signal[:step_size]
    count_matrix[start:start + step_size] += 1
    
    # Update real-time plot
    for i, line in enumerate(lines_reconstructed):
        line.set_data(np.arange(final_reconstructed_signal.shape[0]), final_reconstructed_signal[:, i])
  #      lines_original[i].set_data(np.arange(numerical_data.shape[0]), numerical_data.iloc[:, i])
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
