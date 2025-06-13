import os
import numpy as np
import pandas as pd
from random import shuffle

file_path = "EEG_Recordings/440/Shawn/4 channels/30 sec break"

# Initialize an empty DataFrame to store combined data
combined_df = pd.DataFrame()

# Define class mappings
class_mapping = {
    0: "Nothing",
    1: "Hand open",
    2: "Hand close",
    3: "Ok open",
    4: "Ok close",
    5: "Prong open",
    6: "Prong close",
    16: "Break"
}

def extract_session_and_subject_from_filename(filename):
    # Assumes filename like 'trial_440_Shawn.bin' or 'trial_405_Daniel.bin'
    base = os.path.splitext(filename)[0]
    parts = base.split('_')
    if len(parts) >= 3:
        session = parts[1]
        subject = parts[2]
    else:
        session = ''
        subject = ''
    return session, subject

# Traverse all subdirectories and files
zero_rows = []
for root, dirs, files in os.walk(file_path):
    for file in files:
        print(f"Processing file: {file}")
        if file.endswith(".bin"):
            # Extract session and subject from filename
            session, subject = extract_session_and_subject_from_filename(file)

            # Extract folder name and determine valid classes
            folder_name = os.path.basename(root)

            # Load binary file
            bin_file_path = os.path.join(root, file)
            data_array = np.fromfile(bin_file_path, dtype=np.float32)

            # Ensure data size is a multiple of 6
            trimmed_size = (data_array.size // 6) * 6
            trimmed_data = data_array[:trimmed_size]

            # Reshape into 6 columns
            reshaped_data = trimmed_data.reshape(-1, 6)

            # Create DataFrame
            df = pd.DataFrame(
                reshaped_data,
                columns=["Channel 1", "Channel 2", "Channel 3", "Channel 4", "Class", "Timestamp"]
            )
            # Add session and subject columns
            df['Session'] = session
            df['Subject'] = subject

            # Append to the combined DataFrame
            combined_df = pd.concat([combined_df, df], ignore_index=True)

# Save the combined data to a single CSV file with the header (now includes Session and Subject)
combined_csv_filename = os.path.join(file_path, "combined_data.csv")
combined_df.to_csv(combined_csv_filename, index=False, header=True)