% LSTMtrain.m
Fs = 250;
channel_data = readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/combined_data.csv');
trainIndexes = readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/training_data.csv');

[XTrain, YTrain] = extractLSTMSequences(trainIndexes, channel_data, Fs, "train");

% Normalize training data
allTrain = cat(2, XTrain{:});
mu = mean(allTrain, 2);
sigma = std(allTrain, 0, 2);
for i = 1:numel(XTrain)
    XTrain{i} = (XTrain{i} - mu) ./ sigma;
end

% Train network
net = trainNetwork(XTrain, YTrain, layers, options);

% Save model and normalization stats
save('trainedLSTM.mat', 'net', 'mu', 'sigma');
