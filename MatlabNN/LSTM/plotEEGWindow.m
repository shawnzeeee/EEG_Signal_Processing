function plotEEGWindow(eeg_window, Fs)
    % eeg_window: [samples x channels] (e.g., 500 x 4)
    % Fs: sampling rate (e.g., 250 Hz)

    t = (0:size(eeg_window,1)-1) / Fs;  % time vector in seconds

    figure;
    hold on;
    for ch = 1:size(eeg_window,2)
        plot(t, eeg_window(:,ch) + (ch - 1) * 100);  % offset for visibility
    end
    hold off;

    xlabel('Time (s)');
    ylabel('EEG Channels (offset)');
    title('2-Second EEG Window');
    yticks(0:100:(size(eeg_window,2)-1)*100);
    yticklabels("Ch " + (1:size(eeg_window,2)));
    grid on;
end
