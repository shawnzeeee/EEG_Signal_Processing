import tflite_runtime.interpreter as tflite

# Load the model
interpreter = tflite.Interpreter(model_path="/path/in/container/lstm_model.tflite")

# Allocate tensors
interpreter.allocate_tensors()

# Get input and output tensors
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

# Example of running inference (use your data as input)
input_data = np.random.random(input_details[0]['shape']).astype(np.float32)
interpreter.set_tensor(input_details[0]['index'], input_data)
interpreter.invoke()

# Get the output
output_data = interpreter.get_tensor(output_details[0]['index'])
print("Output:", output_data)
