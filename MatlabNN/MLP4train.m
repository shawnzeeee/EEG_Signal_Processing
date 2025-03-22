%train the MLP with data specified

%can edit options here
options = trainingOptions("adam",MaxEpochs=30,MiniBatchSize=32,InitialLearnRate=0.001, ValidationFrequency=10,plots="training-progress",Verbose=true);

net = trainNetwork(XFeatures, YClasses, layers, options);
