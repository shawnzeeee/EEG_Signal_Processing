%need to create NN beforehand here

%this script will train the NN from a large data file
%using a pre shuffled timestamp vector and extracting features to train the NN

%load data from file
%channel_data = readmatrix('EEG_Recordings/Nick/BP2/TrainingData/combined_data.csv');
%classIndexes= readmatrix('EEG_Recordings/Nick/BP2/TrainingData/training_data.csv');
channel_data = readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/combined_data.csv');
classIndexes= readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/training_data.csv');

%layers = layerGraph(net); 

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
%normalize all data
mu = mean(X_all, 1);             % Mean of each feature across all samples
sigma = std(X_all, [], 1);       % Std dev of each feature
X_all = (X_all - mu) ./ (sigma + eps);

%setup options for training (can alter)
options = trainingOptions("adam", ...
    MaxEpochs=100, ...
    MiniBatchSize=16, ...
    InitialLearnRate=0.001, ...
    LearnRateSchedule="piecewise", ...
    LearnRateDropFactor=0.5, ...
    LearnRateDropPeriod=10, ...
    Shuffle="every-epoch", ...
    Plots="training-progress", ...
    ExecutionEnvironment="auto", ...
    Verbose=true);
net = trainNetwork(X_all, Y_all, layers, options);
