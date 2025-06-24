import numpy as np
import os
import time
import joblib
import subprocess
import sys

from classifier import calculate_hjorth_parameters, calculate_bandpowers



# Load the trained SVM model
model_path = os.path.join(os.path.dirname(__file__), 'svm_model.joblib')
svm = joblib.load(model_path)
print(f"Loaded SVM model from {model_path}")

file_path = os.path.join(os.path.dirname(__file__), 'data.bin')
window_size = 2000  # 2 seconds, 4 channels, 250Hz

print('[INFO] Reading EEG data from data.bin...')

try:
    attention_threshold = 0
    while True:
        data_array = np.fromfile(file_path, dtype=np.float32)
        if len(data_array) < window_size:
            time.sleep(0.1)
            continue
        # Process all complete windows in the file
        for i in range(0, len(data_array) - window_size + 1, window_size):
            eeg_window = data_array[i:i+window_size].reshape(500, 4)
            features = []
            for ch in range(4):
                signal = eeg_window[:, ch]
                mobility, complexity = calculate_hjorth_parameters(signal)
                alpha_power, beta_power = calculate_bandpowers(signal)
                features.extend([mobility, complexity, alpha_power, beta_power])
            features = np.array(features).reshape(1, -1)
            # Predict class
            predicted_class = svm.predict(features)[0]
            adder = -1
            if predicted_class == 2:
                adder = 1

            attention_threshold += adder
            attention_threshold = max(0, min(attention_threshold, 100))

            gesture = "Open"
            if attention_threshold >= 500:
                gesture = "Open"
            print(f"Predicted class: {gesture}")
        # time.sleep(0.5)
except KeyboardInterrupt:
    print("Exiting...")
