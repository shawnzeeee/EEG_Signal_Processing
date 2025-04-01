import os
import numpy as np
import pandas as pd
from random import shuffle

file_path = "EEG_Recordings/Nick/BP2"

# Initialize an empty DataFrame to store combined data
combined_df = pd.DataFrame()

# Define class mappings
class_mapping = {
    0: "Nothing",
    1: "Thumb open",
    2: "Thumb close",
    3: "Index open",
    4: "Index close",
    5: "Middle open",
    6: "Middle close",
    7: "Ring and pinky open",
    8: "Ring and pinky close",
    9: "Full hand open",
    10: "Full hand close"
}

# Traverse all subdirectories and files
zero_rows = []
for root, dirs, files in os.walk(file_path):
    for file in files:
        print(f"Processing file: {file}")
        if file.endswith(".bin"):
            # Extract folder name and determine valid classes
            folder_name = os.path.basename(root)
            valid_classes = [
                int(x) for x in folder_name.replace("3min_Class_", "").split("_") if x.isdigit()
            ]
            # Load binary file
            bin_file_path = os.path.join(root, file)
            data_array = np.fromfile(bin_file_path, dtype=np.float32)

            # Ensure data size is a multiple of 6
            trimmed_size = (data_array.size // 6) * 6
            trimmed_data = data_array[:trimmed_size]

            # Reshape into 6 columns
            reshaped_data = trimmed_data.reshape(-1, 6)


            # Adjust invalid class numbers to 0
            reshaped_data[:, 4] = [
                cls if int(cls) in valid_classes else 0 for cls in reshaped_data[:, 4]
            ]


            # Create DataFrame
            df = pd.DataFrame(
                reshaped_data,
                columns=["Channel 1", "Channel 2", "Channel 3", "Channel 4", "Class", "Timestamp"]
            )


            # Append to the combined DataFrame
            combined_df = pd.concat([combined_df, df], ignore_index=True)

# Save the combined data to a single CSV file without the header
combined_csv_filename = os.path.join(file_path, "combined_data.csv")
combined_df.to_csv(combined_csv_filename, index=False, header=False)


# Extract non-zero classification rows without resetting the index
non_zero_rows = combined_df[combined_df["Class"] != 0]
zero_rows = combined_df[(combined_df["Class"] == 0) & (combined_df.index >= 1) & (combined_df.index <= 90000)]

selected_zero_rows = zero_rows[zero_rows.index.map(lambda x: np.random.randint(1, 2000) == 1)]

final_dataset = pd.concat([selected_zero_rows, non_zero_rows])
#final_dataset = selected_zero_rows


# Shuffle the rows
shuffled_rows = final_dataset.sample(frac=1, random_state=42)

# Create a new DataFrame with the original index and classification columns
shuffled_df = shuffled_rows[["Class"]].copy()
shuffled_df["index"] = shuffled_rows.index

# Split into 80% training and 20% testing
train_size = int(len(shuffled_df) * 0.8)
train_data = shuffled_df.iloc[:train_size]
test_data = shuffled_df.iloc[train_size:]

# Save the training data to a CSV file without the header
train_csv_filename = os.path.join(file_path, "training_data.csv")
train_data.to_csv(train_csv_filename, index=False, header=False)

# Save the testing data to a CSV file without the header
test_csv_filename = os.path.join(file_path, "testing_data.csv")
test_data.to_csv(test_csv_filename, index=False, header=False)


