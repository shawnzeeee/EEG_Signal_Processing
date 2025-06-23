import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Define the file path again
#file_path = "EEG_Recordings/Shawn/BP2/ThumbFromOpen/trial1.bin"

file_path = "EEG_Recordings/440/Nick/4 channels/trial3.bin"
#file_path = "EEG_Recordings/440/Shawn/4 channels/30 sec break/trial_2_S.bin"

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
df.to_csv(csv_filename, index=False)

# Define class mappings
class_mapping = {
    0: "Nothing",
    1: "Hand close",
    2: "Hand open",
    3: "Ok close",
    4: "Ok open",
    5: "Prong close",
    6: "Prong open",
    16: "Break Start"  # Added new classification
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
start = 1000 
end = 140000

# Print all unique classifications that occur in order
class_sequence = classmarkers[start:end]
unique_classes_in_order = [class_sequence[0]] if len(class_sequence) > 0 else []
for c in class_sequence[1:]:
    if c != unique_classes_in_order[-1]:
        unique_classes_in_order.append(c)
print("Classifications in order (from index", start, "to", end, "):")
print([int(c) for c in unique_classes_in_order])

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
        class_value = int(classmarkers[idx + start])
        class_label = class_mapping.get(class_value, "Unknown")
        if class_value == 16:
            plt.scatter(timestamp, amplitude, color='green', zorder=5)  # Green dot for class 16
        else:
            plt.scatter(timestamp, amplitude, color='red', zorder=5)
        plt.text(timestamp, amplitude, class_label, fontsize=8, color='blue', ha='right', va='bottom')
    
    plt.title(f'Channel {i+1}')
    plt.xlabel("Timestamp")
    plt.ylabel("Amplitude")
    plt.legend()

plt.tight_layout()
plt.show()