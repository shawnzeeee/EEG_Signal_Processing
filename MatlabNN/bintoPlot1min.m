fid = fopen('EEG_Recordings/Nick/1minOpenClose/trial5.bin', 'r');
%fid = fopen('EEG_Recordings/Shawn/ArmMovement/OpenClose/data.bin', 'r');

data = fread(fid, 'float32'); % Adjust format if needed
fclose(fid);

% Reshape the data into a 6-col format (each column represents one time step)
reshaped_data = reshape(data, 6, [])'; % Transpose so each row is a time step

% Extract timestamp and channel readings
timestamps = reshaped_data(:, 6);       %6th column: Timestamps
classmarkers = reshaped_data(:, 5);     %5th col : classes
channel_data = reshaped_data(:, 1:4);   %Next 4 columns: Channel readings

sTime = 3000;
eTime = 15000;
% Plot EEG data with timestamps as the x-axis
%ch1 = C3
%ch2 = Cz
%ch3 = P3
%ch4 = Pz

figure;
for i = 1:4
    subplot(4,1,i);
    plot(timestamps(sTime:eTime), channel_data(sTime:eTime, i));
    hold on;

    % Find non-zero class indices in range
    segment_class = classmarkers(sTime:eTime);
    openIndices = find(segment_class == 11);
    closeIndices = find(segment_class == 12);
    
    % Overlay non-zero class markers
    scatter(timestamps(sTime + closeIndices), ...
            channel_data(sTime + closeIndices, i), ...
            20, 'r', 'filled', 'DisplayName', 'Non-zero Class');

    scatter(timestamps(sTime + openIndices), ...
            channel_data(sTime + openIndices, i), ...
            20, 'g', 'filled', 'DisplayName', 'Non-zero Class');

    title(['Channel ', num2str(i)]);
    xlabel('Timestamp');
    ylabel('Amplitude');
end