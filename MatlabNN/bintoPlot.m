%fid = fopen('EEG_Recordings/Daniel/FullHandClose/trial5.bin', 'r');
fid = fopen('data.bin', 'r');
data = fread(fid, 'float32'); % Adjust format if needed
fclose(fid);

% Determine the number of samples (must be a multiple of 5)
num_rows = 12150; % Trim extra data if needed
data = data(1:num_rows); % Ensure proper reshaping

% Reshape the data into a 6-col format (each column represents one time step)
reshaped_data = reshape(data, 6, [])'; % Transpose so each row is a time step

% Extract timestamp and channel readings
timestamps = reshaped_data(:, 6);  % 6 column: Timestamps
classmarkers = reshaped_data(:, 5); % 5 col : classes
channel_data = reshaped_data(:, 1:4); % Next 4 columns: Channel readings

% Plot EEG data with timestamps as the x-axis
figure;
for i = 1:4
    subplot(4,1,i);
    plot(timestamps(200:2025), channel_data(200:2025, i));
    title(['Channel ', num2str(i)]);
    xlabel('Timestamp');
    ylabel('Amplitude');
end