import serial

# Replace 'COMX' with the correct port (e.g., 'COM3' for Windows, '/dev/ttyUSB0' for Linux)
PORT = "COM3"
BAUD_RATE = 9600  # Adjust based on g.Nautilus settings

try:
    # Open serial port
    ser = serial.Serial(PORT, BAUD_RATE, timeout=1)
    print(f"Connected to {PORT}")

    # Read and display 10 lines of data
    for _ in range(10):
        byte = ser.read(1)
    if byte:
        print(f"Byte Received: {byte}")
        data = ser.readline().decode('utf-8', errors='ignore').strip()
        print(f"Received: {data}")
    
    # Close serial port
    ser.close()
    print("Serial connection closed.")

except Exception as e:
    print(f"Error: {e}")
