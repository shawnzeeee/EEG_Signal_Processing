function [X, Y] = extractLSTMSequences(indexSet, channel_data, Fs, rand)
    numFrames = 4;
    frameSize = Fs * 0.5;
    numChannels = 4;
    featuresPerChannel = 5;
    maxJitter = 125;

    X = {};
    Y = [];

    for i = 1:size(indexSet, 1)
        classNumber = indexSet(i,1);
        
        if rand == "train"
            originalCenter = indexSet(i,2);
            % Add random jitter to the center index
            jitter = randi([-maxJitter, maxJitter]);
            centerIndex = originalCenter + jitter;
            leftT = centerIndex - 250;
            rightT = centerIndex + 250;
        elseif rand == "test"
            centerIndex = indexSet(i,2);      
            leftT = centerIndex - 250;
            rightT = centerIndex + 250;
        end



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
