%need to create NN beforehand here
layers = [
    featureInputLayer(20)            % Assuming 5 EEG features per 4 channels
    fullyConnectedLayer(32)          % First hidden layer with 16 neurons
    reluLayer                        % Activation function
    fullyConnectedLayer(13)           % Output layer (10 individual finger open/close, 2 full hand open/close, 1 nothing/baseline)
    softmaxLayer                     % Converts outputs to probabilities
    classificationLayer              % Final classification step
];

%this script will train the NN from a large data file
%using a pre shuffled timestamp vector and extracting features to train the NN

% Load and reshape EEG data into 6 columns, plus padding and label
fid = fopen('EEG_Recordings/Daniel/3minIndexOpenClose_BP2/trial2.bin', 'r');
data = fread(fid, 'float32');
fclose(fid);

% Reshape to 6 columns data
channel_data = reshape(data, 6, [])';
classIndexes = [];
train_counter = 0;
X_all = [];
Y_all = [];
for i = 1:587
    Class = classIndexes(i,1);
    leftT = classIndexes(i,2) - 250;
    rightT = classIndexes(i,2) + 250;

    if leftT > 0 && rightT < 15000
        %extract features
        X = [
            extractEEGFeatures(channel_data(leftT:rightT,1),250);
            extractEEGFeatures(channel_data(leftT:rightT,2),250);
            extractEEGFeatures(channel_data(leftT:rightT,3),250);
            extractEEGFeatures(channel_data(leftT:rightT,4),250)
        ]';
        %create the training features vector and class training vector
        X_all = [X_all; X];
        Y_all = [Y_all; categorical(Class, 0:12)];
    end
end

%setup options for training (can alter)
options = trainingOptions("adam",MaxEpochs=30,MiniBatchSize=64,InitialLearnRate=0.001, ValidationFrequency=10,plots="training-progress",Verbose=true);
%train network
net = trainNetwork(X_all, Y_all, layers, options);

