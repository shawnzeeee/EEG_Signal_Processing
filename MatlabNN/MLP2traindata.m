%load the data for training
fid = fopen('EEG_Recordings/Daniel/FullHandClose/trial4.bin', 'r');
data = fread(fid, 'float32'); % Adjust format if needed
fclose(fid);

% Determine the number of samples (must be a multiple of 5)
num_rows = 12150; % Trim extra data if needed
data = data(1:num_rows); % Ensure proper reshaping

% Reshape the data into a 5-row format (each column represents one time step)
channel_data = reshape(data, 5, [])'; % Transpose so each row is a time step

%extract features and put into one column 1x20
XFeatures1 = extractEEGFeatures(channel_data(500:2000,1),250);
XFeatures2 = extractEEGFeatures(channel_data(500:2000,2),250);
XFeatures3 = extractEEGFeatures(channel_data(500:2000,3),250);
XFeatures4 = extractEEGFeatures(channel_data(500:2000,4),250);

XFeatures = [XFeatures1; XFeatures2; XFeatures3; XFeatures4]';


