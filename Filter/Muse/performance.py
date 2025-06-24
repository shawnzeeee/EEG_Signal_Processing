import numpy as np
import time
import os
from scipy.signal import welch
import pandas as pd

from mne.decoding import CSP
from sklearn.svm import SVC
from sklearn.pipeline import Pipeline
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
import joblib
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay

# Function to calculate mobility and complexity (Hjorth parameters)
def calculate_hjorth_parameters(signal):
    first_derivative = np.diff(signal)
    second_derivative = np.diff(first_derivative)
    variance = np.var(signal)
    mobility = np.sqrt(np.var(first_derivative) / variance)
    complexity = np.sqrt(np.var(second_derivative) / np.var(first_derivative)) / mobility
    return mobility, complexity

# Function to calculate bandpowers (alpha and beta)
def calculate_bandpowers(signal, fs=250):
    freqs, psd = welch(signal, fs=fs, nperseg=fs)
    alpha_band = np.logical_and(freqs >= 8, freqs <= 13)
    beta_band = np.logical_and(freqs >= 13, freqs <= 30)
    alpha_power = np.sum(psd[alpha_band])
    beta_power = np.sum(psd[beta_band])
    return alpha_power, beta_power

all_output_data = []

def process_idle_windows(idle_indices, df, window_size=500, num_windows=4):
    processed_data = []
    channel_names = ["Channel 1", "Channel 2", "Channel 3", "Channel 4"]
    for start_idx in idle_indices:
        for w in range(num_windows):
            window_start = start_idx + w * window_size
            window_end = window_start + window_size
            if window_end > len(df):
                continue
            window = df.iloc[window_start:window_end]
            features = []
            for channel in channel_names:
                signal = window[channel].values
                mobility, complexity = calculate_hjorth_parameters(signal)
                alpha_power, beta_power = calculate_bandpowers(signal)
                features.extend([mobility, complexity, alpha_power, beta_power])
            actual_class = df.iloc[window_start, 4]
            features.append(1)
            processed_data.append(features)
    return processed_data

def process_attention_windows(attention_indices, df, window_size=500, num_windows=4):
    processed_data = []
    channel_names = ["Channel 1", "Channel 2", "Channel 3", "Channel 4"]
    for start_idx in attention_indices:
        for w in range(num_windows):
            window_start = start_idx + w * window_size
            window_end = window_start + window_size
            if window_end > len(df):
                continue
            window = df.iloc[window_start:window_end]
            features = []
            for channel in channel_names:
                signal = window[channel].values
                mobility, complexity = calculate_hjorth_parameters(signal)
                alpha_power, beta_power = calculate_bandpowers(signal)
                features.extend([mobility, complexity, alpha_power, beta_power])
            actual_class = df.iloc[window_start, 4]
            features.append(2)
            processed_data.append(features)
    return processed_data

# Load your CSV file (replace with your actual CSV path)
csv_path = os.path.join(os.path.dirname(__file__), 'calibration.csv')
df = pd.read_csv(csv_path)

# Get indices where class is 2 (attention) and 1 (idle)
attention_indices = df.index[df['Class'] == 2].tolist()
idle_indices = df.index[df['Class'] == 1].tolist()

all_output_data.extend(process_attention_windows(attention_indices, df))
all_output_data.extend(process_idle_windows(idle_indices, df))

all_output_data = np.array(all_output_data)
X = all_output_data[:, :-1]
y = all_output_data[:, -1]

# Reshape for CSP: (n_trials, n_channels, n_times)
n_trials = X.shape[0]
n_channels = 4
n_features_per_channel = 4  # mobility, complexity, alpha, beta
n_times = int(X.shape[1] / n_channels)
X_csp = X.reshape(n_trials, n_channels, n_times)

# 1. CSP + SVM
csp = CSP(n_components=4, reg=None, log=True, norm_trace=False)
svm = SVC(kernel='linear')
pipeline_csp_svm = Pipeline([
    ('csp', csp),
    ('svm', svm)
])
pipeline_csp_svm.fit(X_csp, y)
y_pred_csp_svm = pipeline_csp_svm.predict(X_csp)
cm_csp_svm = confusion_matrix(y, y_pred_csp_svm)
ConfusionMatrixDisplay(confusion_matrix=cm_csp_svm, display_labels=[1, 2]).plot(cmap=plt.cm.Blues)
plt.title('CSP + SVM Confusion Matrix')
plt.show()

# 2. CSP + LDA
lda = LinearDiscriminantAnalysis()
pipeline_csp_lda = Pipeline([
    ('csp', csp),
    ('lda', lda)
])
pipeline_csp_lda.fit(X_csp, y)
y_pred_csp_lda = pipeline_csp_lda.predict(X_csp)
cm_csp_lda = confusion_matrix(y, y_pred_csp_lda)
ConfusionMatrixDisplay(confusion_matrix=cm_csp_lda, display_labels=[1, 2]).plot(cmap=plt.cm.Greens)
plt.title('CSP + LDA Confusion Matrix')
plt.show()

# 3. SVM on features only
svm2 = SVC(kernel='linear')
svm2.fit(X, y)
y_pred_svm = svm2.predict(X)
cm_svm = confusion_matrix(y, y_pred_svm)
ConfusionMatrixDisplay(confusion_matrix=cm_svm, display_labels=[1, 2]).plot(cmap=plt.cm.Oranges)
plt.title('SVM (No CSP) Confusion Matrix')
plt.show()

