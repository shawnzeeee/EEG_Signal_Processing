% LSTMtest.m
Fs = 250;
channel_data = readmatrix('EEG_Signal_Processing\PythonNN\ShawnAndNickTrainingData\combined_data.csv');
testIndexes = readmatrix('EEG_Signal_Processing\PythonNN\ShawnAndNickTrainingData\testing_data.csv');

[XTest, YTest] = extractLSTMSequences(testIndexes, channel_data, Fs, "test");

%Normalize test data using training mu/sigma
for i = 1:numel(XTest)
    XTest{i} = (XTest{i} - mu) ./ sigma;
end

% Predict
YPred = classify(net, XTest);

% Accuracy
accuracy = sum(YPred == YTest) / numel(YTest);
fprintf('Test Accuracy: %.2f%%\n', accuracy * 100);

% Confusion matrix
figure;
confusionchart(YTest, YPred, 'Title', 'LSTM Confusion Matrix');