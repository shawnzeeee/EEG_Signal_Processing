import pandas as pd
import time

# Load the dataset
file_path = "Data/EOG_dataset.csv"
df = pd.read_csv(file_path)

# Simulate real-time data streaming
sampling_rate = 1000  # Hz (samples per second)
delay = 1 / sampling_rate  # Time delay per sample

for index, row in df.iterrows():
    # Extract relevant values
    channel_0 = row["Channel_0"]
    channel_1 = row["Channel_1"]
    channel_3 = row["Channel_3"]

    

    # Simulated stream output
    print(f" CH0: {channel_0}, CH1: {channel_1}, CH3: {channel_3}")
    
    # Simulate real-time delay
    time.sleep(delay)
