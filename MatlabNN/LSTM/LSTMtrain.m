% LSTMtrain.m
Fs = 250;
channel_data = readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/combined_data.csv');
trainIndexes = readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/training_data.csv');

[XTrain, YTrain] = extractLSTMSequences(trainIndexes, channel_data, Fs);

% Normalize training data
allTrain = cat(2, XTrain{:});
mu = mean(allTrain, 2);
sigma = std(allTrain, 0, 2);
for i = 1:numel(XTrain)
    XTrain{i} = (XTrain{i} - mu) ./ sigma;
end

% Define LSTM network
inputSize = 20;
numHiddenUnits = 32;
numClasses = 11;
dropoutRate = 0.3;

layers = [ ...
    sequenceInputLayer(inputSize)
    lstmLayer(numHiddenUnits, 'OutputMode','last')
    fullyConnectedLayer(32)
    reluLayer
    dropoutLayer(dropoutRate)
    fullyConnectedLayer(numClasses)
    softmaxLayer
    classificationLayer];

options = trainingOptions("adam", ...
    MaxEpochs=100, ...
    MiniBatchSize=16, ...
    Shuffle="every-epoch", ...
    Plots="training-progress", ...
    Verbose=true);

% Train network
net = trainNetwork(XTrain, YTrain, layers, options);

% Save model and normalization stats
save('trainedLSTMNet.mat', 'net', 'mu', 'sigma');
