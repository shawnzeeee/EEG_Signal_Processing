% Add npy-matlab utilities (do this once)
addpath("C:\Program Files\MATLAB\R2022b\npy-matlab-master")

% Extract just the first 4 columns
input_data = testWindow(:, 1:4);

% Save as .npy file
writeNPY(single(input_data), 'eeg_input.npy');
