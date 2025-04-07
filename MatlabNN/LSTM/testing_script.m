%testing the LSTM_classify with a sample 2 second wave
Fs = 250;
channel_data = readmatrix('EEG_Signal_Processing\PythonNN\ShawnAndNickTrainingData\combined_data.csv');
test_indexes = readmatrix('EEG_Signal_Processing\PythonNN\ShawnAndNickTrainingData\testing_data.csv');

%generate random 2 second window from our existing data
numSamples = size(test_indexes, 1);  % number of rows
classNum = randi([1, numSamples]);  % random integer between 1 and num of rows
disp("line randomly chosen is " + classNum);
disp("randomly selected class is :" + test_indexes(classNum,1));
disp("timestamp of this class is :" + test_indexes(classNum,2));

%extract time window values
leftT = test_indexes(classNum, 2) - 250;
rightT = test_indexes(classNum, 2) + 250;
disp("channel_data window chosen from lines:" + leftT + " to " + rightT);

% Validate window is in bounds
if leftT > 0 && rightT <= size(channel_data, 1)
    testWindow = channel_data(leftT:rightT, :);
    

    %testing here on 2 second window
    YProb = LSTM_classify(testWindow);
    
    %display results
    disp("Classified Class:");
    disp(double(YProb) - 1);

    %uncomment this if you are using predict
    %[~, predictedClass] = max(YProb, [], 2);
    %disp("Predicted Class:");
    %disp(predictedClass - 1);

else
    error("Chosen window is out of bounds for the EEG data.");
end
