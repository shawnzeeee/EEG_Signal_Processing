%Load data for testing
fid2 = fopen('EEG_Recordings/Daniel/FullHandClose/trial1.bin', 'r');
data2 = fread(fid2, 'float32'); % Adjust format if needed
fclose(fid2);

num_rows = 12150;
data2 = data2(1:num_rows);

test_data = reshape(data2, 5, [])';

XFeatures1test = extractEEGFeatures(test_data(500:2000,1),250);
XFeatures2test = extractEEGFeatures(test_data(500:2000,2),250);
XFeatures3test = extractEEGFeatures(test_data(500:2000,3),250);
XFeatures4test = extractEEGFeatures(test_data(500:2000,4),250);

XFeaturestest = [XFeatures1test; XFeatures2test; XFeatures3test; XFeatures4test]';
