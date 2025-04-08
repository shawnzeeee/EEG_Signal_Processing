import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Define the file path again
file_path = "data.bin"

# Load the binary file and read as float32
data_array = np.fromfile(file_path, dtype=np.float32)

# Ensure data size is a multiple of 5 (each set: 4 channel readings + timestamp)
trimmed_size = (data_array.size // 5) * 5
trimmed_data = data_array[:trimmed_size]

# Reshape into 5 columns: [Channel1, Channel2, Channel3, Channel4, Timestamp]
reshaped_data = trimmed_data.reshape(-1, 5)

# Save reshaped data to CSV file
csv_filename = "reshaped_data.csv"
df = pd.DataFrame(reshaped_data, columns=["Channel 1", "Channel 2", "Channel 3", "Channel 4", "Timestamp"])
df.to_csv(csv_filename, index=False)

# Extract columns
channel_data = reshaped_data[:, :4]  # First 4 columns: EEG readings
timestamps = reshaped_data[:, 4]  # Last column: timestamps

# Plot the EEG data with timestamps on the x-axis
# Plot the EEG data with timestamps on the x-axis (first 1000 points)
plt.figure(figsize=(12, 8))
for i in range(4):  # First 4 columns are EEG channels
    plt.subplot(4, 1, i + 1)
    plt.plot(timestamps[300:2000], channel_data[300:2000, i])
    plt.title(f'Channel {i+1}')
    plt.xlabel("Timestamp")
    plt.ylabel("Amplitude")
    #plt.ylim([channel_data[150:, i].min() , channel_data[150:, i].max() ])  # Stretch y-axis


plt.tight_layout()
plt.show()