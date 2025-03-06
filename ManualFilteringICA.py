import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import FastICA

# Load CSV file
file_path = "Data/EOG_dataset.csv"  # Replace with your actual file path
columns_to_read = ["Channel_0", "Channel_1", "Channel_3","Blink"]  # Replace with actual column names
data = pd.read_csv(file_path, usecols=columns_to_read)


# Ensure the data is numerical
numerical_data = data.select_dtypes(include=[np.number]).dropna()

blink_column = None

blink_column = data["Blink"]
numerical_data = numerical_data.drop(columns=["Blink"])

# Perform ICA
n_components = min(3,numerical_data.shape[0])  # Ensure we don't exceed dimensions

ica = FastICA(n_components=n_components, random_state=42)
components = ica.fit_transform(numerical_data)

print(range(n_components))

# Plot the original EEG signals
plt.figure(figsize=(10, 6))
for i in range(numerical_data.shape[1]):
    plt.plot(numerical_data.iloc[:, i], linewidth=0.8, label=f'Channel {i + 1}')
plt.title("Original EEG Signals")
plt.xlabel("Sample")
plt.ylabel("Amplitude")
plt.legend()
plt.draw()  # Non-blocking


# Plot all 10 ICA components
plt.figure(figsize=(10, 12))
for i in range(n_components):
    plt.subplot(n_components, 1, i + 1)
    plt.plot(components[:, i], linewidth=0.8, label=f'Independent Component {i + 1}')
    if blink_column is not None:
        plt.plot(blink_column * max(components[:, i]), color='red', linestyle='dashed', alpha=0.7, linewidth=0.8, label='Blinks')
    plt.xlabel('Sample')
    plt.ylabel('Amplitude')
    plt.legend()
    plt.tight_layout()
plt.draw()  # Non-blocking


# Remove the component at index 1
filtered_components = components.copy()
filtered_components[:, 1] = 0  # Zero out the second component

# Reconstruct the filtered signal
reconstructed_signal = ica.inverse_transform(filtered_components)

# Plot the reconstructed EEG signal after filtering
plt.figure(figsize=(10, 6))
for i in range(reconstructed_signal.shape[1]):
    plt.plot(reconstructed_signal[:, i], linewidth=0.8, label=f'Reconstructed Channel {i + 1}')
plt.title("Reconstructed EEG Signal (After Removing Component 2)")
plt.xlabel("Sample")
plt.ylabel("Amplitude")
plt.legend()
plt.draw()  # Non-blocking

plt.show()
