function y = mlp_predict(x)
    load('test.mat', 'trainedNetwork');
    y = trainedNetwork(x);
end