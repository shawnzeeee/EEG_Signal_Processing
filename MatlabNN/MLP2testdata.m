%Load data for testing
%fid2 = fopen('EEG_Recordings/Daniel/FullHandClose/trial1.bin', 'r');
fid2 = fopen('EEG_Recordings/Nick/gabeInterruptedMe.bin');
data2 = fread(fid2, 'float32'); % Adjust format if needed
fclose(fid2);

test_data = reshape(data2, 6, [])';

XFeat1test = extractEEGFeatures(test_data(500:15000,1),250);
XFeat2test = extractEEGFeatures(test_data(500:15000,2),250);
XFeat3test = extractEEGFeatures(test_data(500:15000,3),250);
XFeat4test = extractEEGFeatures(test_data(500:15000,4),250);

XFeaturestest = [XFeat1test; XFeat2test; XFeat3test; XFeat4test]';