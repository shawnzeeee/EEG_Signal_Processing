%need to create NN beforehand here

%this script will train the NN from a large data file, identifying when
%each class occurs and extracting features to train the NN

% Load and reshape EEG data into 6 columns, plus padding and label
fid = fopen('EEG_Recordings/Nick/1minOpenClose/trial5.bin', 'r');
data = fread(fid, 'float32');
fclose(fid);

%THIS LINE NEEDS TO BE COMMENTED OUT FOR THE FIRST TRAINING ITERATION,
%OTHERWISE IT NEEDS TO BE HERE TO TRAIN CONTINUOUSLY OVER DIFFERENT FILES
layers = layerGraph(net); 

% Reshape to 6 columns data
channel_data = reshape(data, 6, [])';
train_counter = 0;
X_all = [];
Y_all = [];
for i = 5000:15000
    if channel_data(i,5) ~= 0
        Class = channel_data(i,5);
        leftT = channel_data(i,6) - 250;
        rightT = channel_data(i,6) + 250;

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

