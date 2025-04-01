%need to create NN beforehand here
layers = [
    featureInputLayer(20)            % Assuming 5 EEG features per 4 channels
    fullyConnectedLayer(64)
    reluLayer
    dropoutLayer(0.5)                   % 50% dropout
    fullyConnectedLayer(32)
    reluLayer
    fullyConnectedLayer(11)          % Output layer (8 individual finger open/close, 2 full hand open/close, 1 nothing/baseline)
    softmaxLayer                     % Converts outputs to probabilities
    classificationLayer              % Final classification step
];

%this script will train the NN from a large data file
%using a pre shuffled timestamp vector and extracting features to train the NN

%load data from file
channel_data = readmatrix('EEG_Recordings/Nick/BP2/TrainingData/combined_data.csv');
classIndexes= readmatrix('EEG_Recordings/Nick/BP2/TrainingData/training_data.csv');
%channel_data = readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/combined_data.csv');
%classIndexes= readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/training_data.csv');

X_all = [];
Y_all = [];

for i = 1:size(classIndexes, 1)
    classNumber = classIndexes(i,1);
    leftT = classIndexes(i,2) - 250;
    rightT = classIndexes(i,2) + 250;

    if leftT > 0 && rightT < size(channel_data, 1)
        %extract features
        X = [
            extractEEGFeatures(channel_data(leftT:rightT,1),250);
            extractEEGFeatures(channel_data(leftT:rightT,2),250);
            extractEEGFeatures(channel_data(leftT:rightT,3),250);
            extractEEGFeatures(channel_data(leftT:rightT,4),250);
        ]';
        %create the training features vector and class training vector
        X_all = [X_all; real(X)];
        Y_all = [Y_all; categorical(classNumber, 0:10)];
    else
        disp("training data " + i + " not used, exceeds parameters at time " + classIndexes(i,2) + " with class " + classIndexes(i,1));
    end
end

%setup options for training (can alter)
options = trainingOptions("adam",MaxEpochs=60,MiniBatchSize=32,InitialLearnRate=0.01,Shuffle="every-epoch", plots="training-progress",Verbose=true);
%train network
net = trainNetwork(X_all, Y_all, layers, options);
