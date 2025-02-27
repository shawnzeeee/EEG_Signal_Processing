import serial
import time

PORT = "COM3"  # Replace with your correct COM port
BAUD_RATE = 9600

ser = serial.Serial(PORT, BAUD_RATE, timeout=1)

time.sleep(2)  # Allow time for the connection to establish

while True:
    if ser.in_waiting > 0:  # Check if data is coming
        data = ser.read(1)
        print(f"Byte Received: {data}")
    else:
        print("No data received...")
        time.sleep(1)  # Avoid spamming the output
