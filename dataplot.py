import pandas as pd
import matplotlib.pyplot as plt

# Filepath to the combined data CSV
file_path = "EEG_Recordings/Shawn/BP2/FromHandOpen/combined_data.csv"

# Read the combined data CSV
columns = ["Channel 1", "Channel 2", "Channel 3", "Channel 4", "Class", "Timestamp"]
data = pd.read_csv(file_path, header=None, names=columns)

data = data.iloc[2000:].reset_index(drop=True)

# Plot each channel on a separate subplot
fig, axes = plt.subplots(4, 1, figsize=(12, 8), sharex=True)
channels = ["Channel 1", "Channel 2", "Channel 3", "Channel 4"]

for i, channel in enumerate(channels):
    axes[i].plot(data["Timestamp"], data[channel], label=channel)
    axes[i].set_ylabel(channel)
    axes[i].legend(loc="upper right")

# Add a common X-axis label
axes[-1].set_xlabel("Timestamp")

# Adjust layout and show the plot
plt.tight_layout()
plt.show()
