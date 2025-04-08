function sequence = extractLSTMwindow(eeg_window, Fs)
    %#codegen
    % eeg_window: [500 x 4] EEG data for a 2-second window
    % Fs: sampling frequency (e.g., 250 Hz)

    % Preallocate sequence output: [20 features x 4 frames]
    sequence = zeros(20, 4);

    for frameIdx = 1:4
        frameStart = (frameIdx - 1) * 125 + 1;
        frameEnd   = frameStart + 125 - 1;

        features = [];
        for ch = 1:4
            signal = eeg_window(frameStart:frameEnd, ch);
            f = extractEEGFeatures(signal, Fs);  % [5x1]
            features = [features, f'];           % append [1x5]
        end

        sequence(:, frameIdx) = features';  % store as [20x1]
    end
end
