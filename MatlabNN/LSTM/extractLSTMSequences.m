function [X, Y] = extractLSTMSequences(indexSet, channel_data, Fs)
    numFrames = 4;
    frameSize = Fs * 0.5;
    windowSize = Fs * numFrames / 2;
    numChannels = 4;
    featuresPerChannel = 5;

    X = {};
    Y = [];

    for i = 1:size(indexSet, 1)
        classNumber = indexSet(i,1);
        centerIndex = indexSet(i,2);

        leftT = centerIndex - windowSize;
        rightT = centerIndex + windowSize - 1;

        if leftT > 0 && rightT < size(channel_data, 1)
            sequence = zeros(numChannels * featuresPerChannel, numFrames);

            for frameIdx = 1:numFrames
                frameStart = leftT + (frameIdx - 1) * frameSize;
                frameEnd = frameStart + frameSize - 1;

                features = [];
                for ch = 1:numChannels
                    signal = channel_data(frameStart:frameEnd, ch);
                    f = extractEEGFeatures(signal, Fs);  % [5x1]
                    features = [features, f'];  % [1x5]
                end

                sequence(:, frameIdx) = features';
            end

            X{end+1} = sequence;
            Y(end+1) = categorical(classNumber, 0:10);
        else
            disp("Sample " + i + " skipped (out of bounds)");
        end
    end

    Y = categorical(Y(:));  % ensure it's a categorical column vector
end
