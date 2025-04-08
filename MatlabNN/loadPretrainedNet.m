function net = loadPretrainedNet()
    layers = [
        sequenceInputLayer(20, 'Name', 'sequenceinput')
        lstmLayer(32, 'Name', 'lstm')
        fullyConnectedLayer(32, 'Name', 'fc_1')
        reluLayer('Name', 'relu')
        dropoutLayer(0.3, 'Name', 'dropout')
        fullyConnectedLayer(11, 'Name', 'fc_2')
        softmaxLayer('Name', 'softmax')
        classificationLayer('Name', 'classoutput')
    ];
    net = SeriesNetwork(layers);
end
