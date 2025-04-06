%fid = fopen('EEG_Recordings/Daniel/3minIndexOpenClose_BP2/trial1.bin', 'r');
fid = fopen('EEG_Recordings/Nick/BP2/3minThumbOpenClose/data.bin', 'r');
%fid = fopen('EEG_Recordings/Shawn/3minOpenClose_BP2/trial1.bin', 'r');

data = fread(fid, 'float32'); % Adjust format if needed
fclose(fid);

% Reshape the data into a 6-col format (each column represents one time step)
reshaped_data = reshape(data, 6, [])'; % Transpose so each row is a time step

% Extract timestamp and channel readings
timestamps = reshaped_data(:, 6);       %6th column: Timestamps
classmarkers = reshaped_data(:, 5);     %5th col : classes
channel_data = reshaped_data(:, 1:4);   %Next 4 columns: Channel readings

sTime = 500;
eTime = 45000;
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
    %Class0     % Nothing
    %Class1     % Thumb open
    %Class2     % Thumb close
    %Class3     % Index open
    %Class4     % Index close
    %Class5     % Middle open
    %Class6     % Middle close
    %Class7     % Ring and pinky open
    %Class8     % Ring and pinky close
    %Class9     % Full hand open
    %Class10    % Full hand close
    
    openThumb = find(segment_class == 1);
    closeThumb = find(segment_class == 2);
    openIndex = find(segment_class == 3);
    closeIndex = find(segment_class == 4);
    openMiddle = find(segment_class == 5);
    closeMiddle = find(segment_class == 6);
    openRingPinky = find(segment_class == 7);
    closeRingPinky = find(segment_class == 8);
    openHand = find(segment_class == 9);
    closeHand = find(segment_class == 10);
    
    % Overlay non-zero class marker
    scatter(timestamps(sTime + openThumb), channel_data(sTime + openThumb, i), 20, 'yellow', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + closeThumb), channel_data(sTime + closeThumb, i), 20, 'red', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + openIndex), channel_data(sTime + openIndex, i), 20, 'green', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + closeIndex), channel_data(sTime + closeIndex, i), 20, 'red', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + openMiddle), channel_data(sTime + openMiddle, i), 20, 'blue', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + closeMiddle), channel_data(sTime + closeMiddle, i), 20, 'red', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + openRingPinky), channel_data(sTime + openRingPinky, i), 20, 'cyan', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + closeRingPinky), channel_data(sTime + closeRingPinky, i), 20, 'red', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + openHand), channel_data(sTime + openHand, i), 20, 'green', 'filled', 'DisplayName', 'Non-zero Class');
    scatter(timestamps(sTime + closeHand), channel_data(sTime + closeHand, i), 20, 'red', 'filled', 'DisplayName', 'Non-zero Class');

    title(['Channel ', num2str(i)]);
    xlabel('Timestamp');
    ylabel('Amplitude');
end