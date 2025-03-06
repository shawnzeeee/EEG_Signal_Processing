import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import FastICA
from scipy.stats import pearsonr

# Load CSV file
file_path = "Data/EOG_dataset.csv"  # Replace with your actual file path
columns_to_read = ["Channel_0", "Channel_1", "Channel_3"]  # Replace with actual column names
data = pd.read_csv(file_path, usecols=columns_to_read)

# Ensure the data is numerical
numerical_data = data.select_dtypes(include=[np.number]).dropna()

# Compute ICA on the entire dataset
n_components = min(3, numerical_data.shape[1])  # Ensure we don't exceed dimensions
ica = FastICA(n_components=n_components, random_state=42)
components = ica.fit_transform(numerical_data)

# Extract rows 797 to 897 of the second ICA component as the new blink reference
blink_reference = components[797:897, 1]

# Compute the original method blink reference by applying ICA only on rows 797 to 897
ica_original = FastICA(n_components=n_components, random_state=42)
original_components = ica_original.fit_transform(numerical_data.iloc[797:897])
original_blink_reference = original_components[:, 1]

# Plot both blink references
plt.figure(figsize=(10, 4))
plt.plot(blink_reference, linewidth=0.8, color='red', label='ICA Blink Reference (Full Data)')
plt.plot(original_blink_reference, linewidth=0.8, color='blue', linestyle='dashed', label='ICA Blink Reference (Subset)')
plt.title("Blink Reference Signals")
plt.xlabel("Sample")
plt.ylabel("Amplitude")
plt.legend()
plt.show()

# Moving window parameters
window_size = 40  # Number of rows per window
step_size = 20  # Overlapping step size

# Storage for final reconstructed signal
final_reconstructed_signal = np.zeros_like(numerical_data)
count_matrix = np.zeros_like(numerical_data)  # To track contributions for averaging

plotItr = False
# Process data in moving windows
for start in range(0, numerical_data.shape[0] - window_size, step_size):
    window_data = numerical_data.iloc[start:start + window_size]
    
    ica_window = FastICA(n_components=n_components, random_state=42, whiten='unit-variance')
    window_components = ica_window.fit_transform(window_data)
    
    # Identify components to remove
    components_to_remove = []
    for i in range(n_components):
        # Pearson Correlation
        corr, _ = pearsonr(window_components[:, i], components[start:start +window_components.shape[0], i])
        
        #print(f"Window {start}-{start + window_size} | Component {i+1}: Pearson Correlation: {corr:.4f}")
        
        if abs(corr) > 0.9:
            components_to_remove.append(i)
            print(f"Component {i+1} flagged for removal due to high similarity to blink.")
            plotItr = True

    
        # Remove flagged components
        filtered_components = window_components.copy()
        for comp in components_to_remove:
            filtered_components[:, comp] = 0  # Zero out the identified component
        
            # Reconstruct the filtered signal
        reconstructed_signal = ica_window.inverse_transform(filtered_components)

        # Append to final reconstructed signal using step size to avoid redundancy
        final_reconstructed_signal[start:start + step_size] += reconstructed_signal[-step_size:]
        count_matrix[start:start + step_size] += 1

# Normalize the final signal by dividing by count matrix to average overlapping values
#final_reconstructed_signal[count_matrix > 0] /= count_matrix[count_matrix > 0]

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
