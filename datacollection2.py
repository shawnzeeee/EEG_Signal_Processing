import serial
import time

PORT = "COM3"  # Replace with your correct COM port
BAUD_RATE = 9600

ser = serial.Serial(PORT, BAUD_RATE, timeout=1)

time.sleep(2)  # Allow time for the connection to establish

# ser.write(b'START\n')  # Send start command
# ser.write(b'\x02')  # Some devices use binary start signals
# ser.write(b'\xAA\x55')  # Some devices use a special header

while True:
    if ser.in_waiting > 0:  # Check if data is coming
        data = ser.read(1)
        print(f"Byte Received: {data}")
    else:
        print("No data received...")
        time.sleep(0.2)  # Avoid spamming the output