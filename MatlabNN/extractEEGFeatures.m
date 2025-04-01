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
    alpha_power = bandpower(pxx, f, [8 13],'psd');

    % Beta power (13–30 Hz)
    beta_power = bandpower(pxx, f, [13 30],'psd');

    %Root Mean Square (RMS)
    rms_value = rms(eeg_signal);
    
    % Compute Hjorth parameters
    % First and second derivatives
    firstDeriv = diff(eeg_signal);
    secondDeriv = diff(firstDeriv);

    % Variances
    var0 = var(eeg_signal);
    var1 = var(firstDeriv);
    var2 = var(secondDeriv);

    % Mobility and complexity
    mobility = sqrt(var1 / var0);
    complexity = sqrt((var2 / var1) - (var1 / var0));
    %Hjorth Parameters
    %mobility = std(diff(eeg_signal)) / std(eeg_signal);
    %complexity = std(diff(diff(eeg_signal))) / std(diff(eeg_signal));
    
    %Zero Crossing Rate (ZCR)
    %ZCR = sum(abs(diff(sign(eeg_signal)))) / length(eeg_signal);
    
    %Kurtosis
    %kurtosis_value = kurtosis(eeg_signal);
    
    %Shannon Entropy
    %prob_dist = abs(eeg_signal) ./ sum(abs(eeg_signal));  % Normalize
    %entropy_value = -sum(prob_dist .* log2(prob_dist + eps));  % Compute entropy
    
    % Combine features into a vector
    features = [alpha_power; beta_power; rms_value; mobility; complexity];

    %normalize features
    features = (features - mean(features)) ./ (std(features) + eps);
end
