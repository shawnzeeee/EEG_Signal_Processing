clear;

inputSize = 20;
numHiddenUnits = 32;
numClasses = 11;        
dropoutRate = 0.3;
fullyConnectedLayer1 = 16   ;
EPOCHS = 500;
MiniBatchSize = 16;
InitialLearnRate=0.001;


layers = [ ...
    sequenceInputLayer(inputSize)
    lstmLayer(numHiddenUnits, OutputMode="last")
    fullyConnectedLayer(fullyConnectedLayer1)
    reluLayer()
    dropoutLayer(dropoutRate)
    fullyConnectedLayer(numClasses)
    softmaxLayer()
    classificationLayer()];

options = trainingOptions("adam", ...
    MaxEpochs=EPOCHS, ...
    MiniBatchSize=MiniBatchSize, ...
    InitialLearnRate=InitialLearnRate,...
    Shuffle="every-epoch", ...
    Plots="training-progress", ...
    Verbose=true, ...
    ExecutionEnvironment="gpu");
