import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Define the file path again
file_path = "EEG_Recordings/Shawn/1minOpenClose/trial5.bin"

# Load the binary file and read as float32
data_array = np.fromfile(file_path, dtype=np.float32)

# Ensure data size is a multiple of 6 (each set: 4 channel readings + class + timestamp)
trimmed_size = (data_array.size // 6) * 6
trimmed_data = data_array[:trimmed_size]

# Reshape into 6 columns: [Channel1, Channel2, Channel3, Channel4, Class, Timestamp]
reshaped_data = trimmed_data.reshape(-1, 6)

# Save reshaped data to CSV file
csv_filename = "reshaped_data.csv"
df = pd.DataFrame(reshaped_data, columns=["Channel 1", "Channel 2", "Channel 3", "Channel 4", "Class", "Timestamp"])
df.to_csv(csv_filename, index=False)

# Extract columns
channel_data = reshaped_data[:, :4]  # First 4 columns: EEG readings
classmarkers = reshaped_data[:, 4]  # 5th column: Class
timestamps = reshaped_data[:, 5]  # Last column: timestamps

# Plot the EEG data with timestamps on the x-axis and non-zero class markings
start = 2000
end = 4000
plt.figure(figsize=(12, 8))
for i in range(4):  # First 4 columns are EEG channels
    plt.subplot(4, 1, i + 1)
    
    # Plot the channel data
    plt.plot(timestamps[start:end], channel_data[start:end, i], label=f'Channel {i+1}')
    
    # Find timestamps where class is non-zero
    non_zero_indices = np.where(classmarkers[start:end] != 0)[0]
    
    # Mark the non-zero class timestamps
    plt.scatter(timestamps[non_zero_indices + start], channel_data[non_zero_indices + start, i], 
                color='red', label='Non-zero Class', zorder=5)
    
    plt.title(f'Channel {i+1}')
    plt.xlabel("Timestamp")
    plt.ylabel("Amplitude")
    plt.legend()

plt.tight_layout()
plt.show()