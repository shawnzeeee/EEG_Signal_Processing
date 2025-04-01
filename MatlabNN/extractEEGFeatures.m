function features = extractEEGFeatures(eeg_signal, fs)
    % Input:
    % eeg_signal - EEG time-series data (1D array)
    % fs - Sampling frequency (Hz)
    %
    % Output:
    % features - Feature vector containing extracted values
    
    % Power spectral density using Welch's method
    [pxx, f] = pwelch(eeg_signal, hamming(256), 128, 512, fs);

    % Alpha power (8–13 Hz)
    alphaIdx = f >= 8 & f <= 13;
    alpha_power = bandpower(pxx, f, [8 13],'psd');

    % Beta power (13–30 Hz)
    betaIdx = f >= 13 & f <= 30;
    beta_power = bandpower(pxx, f, [13 30],'psd');

    %   Power in Alpha (8-13 Hz) and Beta (13-30 Hz) Bands
    %[pxx, f] = pwelch(eeg_signal, [], [], [], fs);  % Power Spectral Density
    % Compute Alpha and Beta Band Power Directly from Time-Domain Signal
    %alpha_power = bandpower(eeg_signal, fs, [8 13]);  % Alpha (8-13 Hz)
    %beta_power = bandpower(eeg_signal, fs, [13 30]);  % Beta (13-30 Hz)

    %Root Mean Square (RMS)
    rms_value = rms(eeg_signal);
    
    %Hjorth Parameters
    mobility = std(diff(eeg_signal)) / std(eeg_signal);
    complexity = std(diff(diff(eeg_signal))) / std(diff(eeg_signal));
    
    %Zero Crossing Rate (ZCR)
    %ZCR = sum(abs(diff(sign(eeg_signal)))) / length(eeg_signal);
    
    %Kurtosis
    %kurtosis_value = kurtosis(eeg_signal);
    
    %Shannon Entropy
    %prob_dist = abs(eeg_signal) ./ sum(abs(eeg_signal));  % Normalize
    %entropy_value = -sum(prob_dist .* log2(prob_dist + eps));  % Compute entropy
    
    % Combine features into a vector
    features = [alpha_power; beta_power; rms_value; mobility; complexity];
end
