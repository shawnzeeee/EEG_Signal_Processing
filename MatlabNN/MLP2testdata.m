%Load data for testing
fid2 = fopen('EEG_Recordings/Nick/singleHandClose/trial1.bin');
data2 = fread(fid2, 'float32'); % Adjust format if needed
fclose(fid2);

test_data = reshape(data2, 6, [])';
sTime = 300;
eTime = 2000;

XFeat1test = extractEEGFeatures(test_data(sTime:eTime,1),250);
XFeat2test = extractEEGFeatures(test_data(sTime:eTime,2),250);
XFeat3test = extractEEGFeatures(test_data(sTime:eTime,3),250);
XFeat4test = extractEEGFeatures(test_data(sTime:eTime,4),250);

XFeaturestest = [XFeat1test; XFeat2test; XFeat3test; XFeat4test]';