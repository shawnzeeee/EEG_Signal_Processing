YProbabilities = predict(net, XFeaturestest);  % Get probabilities for each class
%Yclassify = classify(net, XFeaturestest);

% Display probabilities
disp("Predicted Class Probabilities:");
disp(YProbabilities);

%disp("Predicted Class classification:");
%disp("Classified Class:");
%disp(Yclassify);

% Get the predicted class with highest probability
[~, predictedClass] = max(YProbabilities, [], 2);
disp("Predicted Class:");
disp(predictedClass - 1);
