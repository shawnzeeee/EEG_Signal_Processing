import pandas as pd
import matplotlib.pyplot as plt

file_path = r"C:\Users\shawn\EEG_Signal_Processing\HandGestureDataCollection\15minVideo\MuseRecording\muse_stream_.csv"

# Read the CSV file
df = pd.read_csv(file_path)

# Plot each channel in a separate subplot (same window)
fig, axes = plt.subplots(4, 1, figsize=(15, 10), sharex=True)
for i in range(4):
    axes[i].plot(df.index, df.iloc[:, i])
    axes[i].set_ylabel(f'Ch {i+1}')
    axes[i].set_title(f'EEG Channel {i+1}')

axes[-1].set_xlabel('Sample')
plt.tight_layout()
plt.show()