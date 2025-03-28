fid = fopen('EEG_Recordings/Daniel/BaseRecording/trial3.bin', 'r');
data = fread(fid, 'float32'); % Adjust format if needed
fclose(fid);

% Reshape the data into a 6 or 5-col format (each column represents one time step)
reshaped_data = reshape(data, 5, [])'; % Transpose so each row is a time step

% Extract timestamp and channel readings
timestamps = reshaped_data(:, 5);       %6th column: Timestamps
channel_data = reshaped_data(:, 1:4);   %Next 4 columns: Channel readings

sTime = 500;
eTime = 2504;
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
    
    title(['Channel ', num2str(i)]);
    xlabel('Timestamp');
    ylabel('Amplitude');
end