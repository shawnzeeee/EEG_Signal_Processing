% Define the neural network layers
layers = [
    featureInputLayer(20)            % Assuming 5 EEG features per 4 channels
    fullyConnectedLayer(16)          % First hidden layer with 16 neurons
    batchNormalizationLayer
    reluLayer                        % Activation function
    fullyConnectedLayer(64)
    reluLayer
    fullyConnectedLayer(11)           % Output layer (10 individual finger open/close, 2 full hand open/close, 1 nothing/baseline)
    softmaxLayer                     % Converts outputs to probabilities
    classificationLayer              % Final classification step
];

%analyzeNetwork(layers);