clear;

% Define the neural network layers
layers = [
    featureInputLayer(20)            % Assuming 5 EEG features per 4 channels
    fullyConnectedLayer(16)          % First hidden layer with 16 neurons
    reluLayer                        % Activation function
    fullyConnectedLayer(11)           % Output layer (11 classes)
    softmaxLayer                     % Converts outputs to probabilities
    classificationLayer              % Final classification step
];

%analyzeNetwork(layers);