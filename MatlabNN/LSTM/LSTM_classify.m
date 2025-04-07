function out = LSTM_classify(inputWindow)
    load('LSTM0.1.2.mat', 'net', 'mu', 'sigma'); %change this to your best trained model + normalization values    
    input = extractLSTMwindow(inputWindow,250);
    inputStandardized = (input - mu) ./ sigma;
    %out = predict(net, inputStandardized);      %use this if you want percentages of each class
    out = classify(net, inputStandardized);      %use this if you want a single class output
end
