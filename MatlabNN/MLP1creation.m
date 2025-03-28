% Define the neural network layers
layers = [
    featureInputLayer(20)            % Assuming 5 EEG features per 4 channels
    fullyConnectedLayer(32)          % First hidden layer with 16 neurons
    reluLayer                        % Activation function
    fullyConnectedLayer(13)           % Output layer (10 individual finger open/close, 2 full hand open/close, 1 nothing/baseline)
    softmaxLayer                     % Converts outputs to probabilities
    classificationLayer              % Final classification step
];

%analyzeNetwork(layers);