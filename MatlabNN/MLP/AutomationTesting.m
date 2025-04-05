%testing script for automation training 2 using the testing time stamps

%load channel data and testing time stamps
%channel_data = readmatrix('EEG_Recordings/Nick/BP2/TrainingData/combined_data.csv');
%testIndexes= readmatrix('EEG_Recordings/Nick/BP2/TrainingData/testing_data.csv');
channel_data = readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/combined_data.csv');
testIndexes= readmatrix('EEG_Recordings/Shawn/BP2/TrainingData/testing_data.csv');

X_test = [];
Y_test = [];

for i = 1:size(testIndexes, 1)
    classNumber = testIndexes(i,1);
    leftT = testIndexes(i,2) - 250;
    rightT = testIndexes(i,2) + 250;

    if leftT > 0 && rightT < size(channel_data, 1)
        %extract features
        X = [
            extractEEGFeatures(channel_data(leftT:rightT,1),250);
            extractEEGFeatures(channel_data(leftT:rightT,2),250);
            extractEEGFeatures(channel_data(leftT:rightT,3),250);
            extractEEGFeatures(channel_data(leftT:rightT,4),250);
        ]';
        %create the training features vector and class training vector
        X_test = [X_test; real(X)];
        Y_test = [Y_test; categorical(classNumber, 0:10)];
    else
        disp("testing data " + i + " not used, exceeds parameters at time " + testIndexes(i,2) + " with class " + testIndexes(i,1));
    end
end

mu = mean(X_test);
sigma = std(X_test);
X_test = (X_test - mu) ./ sigma;


test_results = [];
YPreds = predict(net, X_test);                 % All predictions at once
[~, predictedClasses] = max(YPreds, [], 2);    % Class with highest probability
predictedLabels = predictedClasses - 1;        % Adjust to 0-based class labels

disp("testing complete, outputting results:");

%disp(predictedLabels');
%disp(Y_test');
trueLabels = str2double(string(Y_test));
accuracy = sum(predictedLabels == trueLabels) / numel(trueLabels);

disp("Test Accuracy: " + round(accuracy * 100, 2) + "%");

confusionchart(Y_test, categorical(predictedLabels, 0:10));

