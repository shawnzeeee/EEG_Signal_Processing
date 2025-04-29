import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Define the file path again
file_path = "EEG_Recordings/Shawn/BP2/ThumbFromOpen/trial1.bin"

#file_path = "EEG_Recordings/Shawn/1minOpenClose/trial5.bin"
# file_path = "EEG_Recordings/data.bin"

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

# Define class mappings
class_mapping = {
    0: "Nothing",
    1: "Thumb open",
    2: "Thumb close",
    3: "Index open",
    4: "Index close",
    5: "Middle open",
    6: "Middle close",
    7: "Ring and pinky open",
    8: "Ring and pinky close",
    9: "Full hand open",
    10: "Full hand close"
}

# Add a new column for class descriptions
df["Class Description"] = df["Class"].map(class_mapping)

# Save updated data to CSV file
csv_filename = "reshaped_data_with_classes.csv"
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
    for idx in non_zero_indices:
        timestamp = timestamps[idx + start]
        amplitude = channel_data[idx + start, i]
        class_label = class_mapping.get(int(classmarkers[idx + start]), "Unknown")
        plt.scatter(timestamp, amplitude, color='red', zorder=5)
        plt.text(timestamp, amplitude, class_label, fontsize=8, color='blue', ha='right', va='bottom')
    
    plt.title(f'Channel {i+1}')
    plt.xlabel("Timestamp")
    plt.ylabel("Amplitude")
    plt.legend()

plt.tight_layout()
plt.show()