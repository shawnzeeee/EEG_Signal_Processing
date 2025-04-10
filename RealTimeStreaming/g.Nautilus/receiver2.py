import mmap
import struct
import numpy as np
import torch
import time
from CNNBiLSTM import CNNBiLSTMClassifier
import serial
import socket

model_path = "model.pth"
ESP_IP = "192.168.35.59"  # Replace with ESP's IP (check Serial output)
ESP_PORT = 1234

REQUEST_DATA = "Local\\RequestData"
READY_DATA = "Local\\ReadyData"
INPUT_WINDOW = "Local\\InputWindow"

INPUT_SCAN_SIZE = "Local\\InputScanSize"
INPUT_SCAN = "Local\\InputScan"


def reshape_data(data_array):
    """
    Reshape the input data to extract only the channel data (shape: 4, 500).
    :param data_array: 1D numpy array with repeating patterns of [timestamp, ch1, ch2, ch3, ch4].
    :return: 2D numpy array with shape (4, 500).
    """
    # Ensure data size is a multiple of 2500 (500 timestamps + 500 * 4 channels)
    trimmed_size = (data_array.size // 2500) * 2500
    trimmed_data = data_array[:trimmed_size]

    # Reshape into 2D array: [500 timestamps, 5 columns (Timestamp, Ch1, Ch2, Ch3, Ch4)]
    reshaped_raw = trimmed_data.reshape(500, 5)  # 5 columns: Timestamp, Ch1, Ch2, Ch3, Ch4

    # Extract only the channel data (Ch1, Ch2, Ch3, Ch4) and transpose to shape (4, 500)
    channel_data = reshaped_raw[:, 1:5].T  # Transpose to get (4, 500)

    return channel_data

def read_shared_memory(shared_mem_name, data_size):
    # Open shared memory
    with mmap.mmap(-1, data_size, shared_mem_name, access=mmap.ACCESS_READ) as shm:
        # Read data as float32
        data_array = np.frombuffer(shm, dtype=np.float32)
        reshaped_data = reshape_data(data_array)
        return reshaped_data

# Example usage
# shared_mem_name = "EEG_SharedMemory"  # Replace with actual shared memory name
# data_size = 2500 * 4  # 2500 floats (500 timestamps + 500 * 4 channels)
# reshaped_data = read_shared_memory(shared_mem_name, data_size)


def generate_dummy_data(num_samples):
    """
    Generate a 1D array with repeating patterns of [timestamp, ch1, ch2, ch3, ch4].
    :param num_samples: Number of samples (each sample has 5 values: timestamp, ch1, ch2, ch3, ch4)
    :return: 1D numpy array
    """
    timestamps = np.arange(num_samples)  # Sequential timestamps
    ch1 = np.random.rand(num_samples)   # Random values for channel 1
    ch2 = np.random.rand(num_samples)   # Random values for channel 2
    ch3 = np.random.rand(num_samples)   # Random values for channel 3
    ch4 = np.random.rand(num_samples)   # Random values for channel 4

    # Stack the data into a 2D array and flatten it into a 1D array
    data = np.column_stack((timestamps, ch1, ch2, ch3, ch4)).flatten()
    return data



# Example usage
num_samples = 500  # Number of samples (500 timestamps + 500 * 4 channels)


model = CNNBiLSTMClassifier(num_classes=11)  # Adjust `num_classes` as needed
model.load_state_dict(torch.load(model_path, map_location="cpu"))
model.eval()

# Send the classification via UART
serial_port = "COM4"  # Replace with the correct COM port for your ESP32
baud_rate = 115200

#with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
#    sock.connect((ESP_IP, ESP_PORT))
#    print("Connection Established)")
#    time.sleep(1)  # Optional, in case ESP needs time after connect

classification = 0

while True:
    try:
        time.sleep(0.5)
        with mmap.mmap(-1, 4, READY_DATA, access=mmap.ACCESS_READ) as ready_shm:
            ready_flag = struct.unpack("i", ready_shm.read(4))[0]  # Read READY_DATA as an integer

        if ready_flag == 1:  # Check if READY_DATA is set to true
            file_path = "window.bin"

            # Load the binary file and read as float32
            data_array = np.fromfile(file_path, dtype=np.float32)

            reshaped_data = reshape_data(data_array)  # Reshape the data
            
            # Run model prediction
            input_tensor = torch.tensor(reshaped_data, dtype=torch.float32).unsqueeze(0)  # Shape: (1, 4, 500)
            output = model(input_tensor)
            preds = torch.argmax(output, dim=1)
            classification = preds.item()  # Extract integer class

            print("Sent classification:", classification)
            
            with mmap.mmap(-1, 4, READY_DATA, access=mmap.ACCESS_WRITE) as ready_shm:
                ready_shm.seek(0)
                ready_shm.write(struct.pack("i", 1))  # Write 1 to REQUEST_DATA

        # Send classification as a 1-byte value (0–255)
#           sock.sendall(struct.pack("B", classification))  # Use "i" for 4-byte int if needed

        # Set REQUEST_DATA flag to 1
        with mmap.mmap(-1, 4, REQUEST_DATA, access=mmap.ACCESS_WRITE) as request_shm:
            request_shm.seek(0)
            request_shm.write(struct.pack("i", 1))  # Write 1 to REQUEST_DATA

    except Exception as e:
        print(f"Error occurred: {e}")
        # Set REQUEST_DATA flag to 2 to indicate an error
        with mmap.mmap(-1, 4, REQUEST_DATA, access=mmap.ACCESS_WRITE) as request_shm:
            request_shm.seek(0)
            request_shm.write(struct.pack("i", 2))  # Write 2 to REQUEST_DATA