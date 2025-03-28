%need to create NN beforehand here

%this script will train the NN from a large data file for the baseline

% Load and reshape EEG data into 6 columns, plus padding and label
fid = fopen('EEG_Recordings/Nick/1minBaseline/trial5.bin', 'r');
data = fread(fid, 'float32');
fclose(fid);

%THIS LINE NEEDS TO BE COMMENTED OUT FOR THE FIRST TRAINING ITERATION,
%OTHERWISE IT NEEDS TO BE HERE TO TRAIN CONTINUOUSLY OVER DIFFERENT FILES
%layers = layerGraph(net); 

% Reshape to 6 columns data
channel_data = reshape(data, 6, [])';
train_counter = 0;
train_baseline_index = 4000;
X_all = [];
Y_all = [];
for i = 3000:15000
    if train_baseline_index == i
        Class = 0;
        leftT = train_baseline_index - 250;
        rightT = train_baseline_index + 250;
        train_baseline_index = train_baseline_index + 1000;
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
            train_counter = train_counter + 1;
        end
    end
end
%setup options for training (can alter)
options = trainingOptions("adam",MaxEpochs=20,MiniBatchSize=32,InitialLearnRate=0.001, ValidationFrequency=10,plots="training-progress",Verbose=true);
%train network
net = trainNetwork(X_all, Y_all, layers, options);

disp("trained NN " + train_counter + " times");

