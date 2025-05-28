import os
import numpy as np
import pandas as pd
from random import shuffle


file_path = "EEG_Recordings/ShawnAndNick"

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