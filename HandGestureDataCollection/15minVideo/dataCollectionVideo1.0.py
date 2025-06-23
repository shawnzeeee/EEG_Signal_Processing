import cv2
import time
import random
import numpy as np
import os
import mmap
import struct
import math
import csv

script_dir = os.path.dirname(os.path.abspath(__file__))

SHARED_MEMORY_NAME = "Local\\GestureSharedMemory"
SHARED_MEMORY_SIZE = 256
shm = mmap.mmap(-1, SHARED_MEMORY_SIZE, SHARED_MEMORY_NAME, access=mmap.ACCESS_WRITE)

#classifications of hand gestures:
#Idle           = 0
#Hand close     = 1
#Hand open      = 2
#Ok close       = 3
#Ok open        = 4
#Prong close    = 5
#Prong open     = 6

# --- CONFIG ---
video_list = [ 
         os.path.join(script_dir,"GestureVideos/Handclose2.mp4"),
         #os.path.join(script_dir,"GestureVideos/Handopen2.mp4"), 
         os.path.join(script_dir,"GestureVideos/Okclose2.mp4"),
         #os.path.join(script_dir,"GestureVideos/Okopen2.mp4"), 
         os.path.join(script_dir,"GestureVideos/Prongclose2.mp4"),
         #os.path.join(script_dir,"GestureVideos/Prongopen2.mp4"), 
]

#for controlled randomness
play_counts = {path: 0 for path in video_list}

play_order = []

gesture_labels = {
    "Handopen2.mp4": "Open Hand",
    "Handclose2.mp4": "Close Hand",
    "Okopen2.mp4": "OK Sign (Open)",
    "Okclose2.mp4": "OK Sign (Close)",
    "Prongopen2.mp4": "Prong Gesture (Open)",
    "Prongclose2.mp4": "Prong Gesture (Close)",
}

cycle_duration = 2 * 60   # 2 minutes per video session
break_duration = 0.5 * 60   # 2-minute break
total_duration = 15 * 60  # total session time

# --- HELPER FUNCTIONS ---
def send_gesture_classification(gesture_code):
    """Writes an integer gesture classification (0 to 15) into shared memory."""
    print(f"sending gesture classification", gesture_code)
    shm.seek(0)
    shm.write(struct.pack('i', gesture_code))

def get_least_played_video():
    min_play = min(play_counts.values())
    candidates = [v for v in video_list if play_counts[v] == min_play]
    chosen = random.choice(candidates)
    play_counts[chosen] += 1
    return chosen

def play_video_then_countdown(path, gesture_index):
    cap = cv2.VideoCapture(path)
    if not cap.isOpened():
        print(f"Cannot open: {path}")
        return

    frame_rate = 120
    last_frame = None
    cv2.namedWindow("Display", cv2.WINDOW_NORMAL)
    cv2.resizeWindow("Display", 720, 720)
    
    # --- Play the video and remember the last frame ---
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        last_frame = frame.copy()
        
        resized_frame = cv2.resize(frame, (720, 720))

        # Draw custom title
        filename = os.path.basename(path)
        label = gesture_labels.get(filename, filename)
        # --- Draw centered label with box ---
        font = cv2.FONT_HERSHEY_SIMPLEX
        font_scale = 1.2
        thickness = 3
        text_size, baseline = cv2.getTextSize(label, font, font_scale, thickness)
        text_width, text_height = text_size

        # Center position
        center_x = resized_frame.shape[1] // 2
        text_x = center_x - text_width // 2
        text_y = 60  # distance from top

        # Draw background rectangle
        box_padding = 10
        top_left = (text_x - box_padding, text_y - text_height - box_padding)
        bottom_right = (text_x + text_width + box_padding, text_y + baseline + box_padding)
        cv2.rectangle(resized_frame, top_left, bottom_right, (255, 255, 255), -1)  # White box
        cv2.rectangle(resized_frame, top_left, bottom_right, (0, 0, 0), 2)         # Black border

        # Draw label text
        cv2.putText(resized_frame, label, (text_x, text_y), font,
                    font_scale, (0, 0, 0), thickness)
        
        # Calculate progress bar based on session time
        elapsed = time.time() - session_start
        progress = min(elapsed / total_duration, 1.0)
        draw_progress_bar(resized_frame, progress)
        
        cv2.imshow("Display", resized_frame)
        last_frame = resized_frame.copy()

        if cv2.waitKey(int(1500 // frame_rate)) & 0xFF == ord('q'):
            exit(0)

    cap.release()

    if last_frame is None:
        print("Error: No valid frame captured.")
        return

    h, w, _ = last_frame.shape
    x = int(w * 0.75) - 30  # 75% across width
    y = int(h / 2) + 20     # Vertically centered

    # --- Show 3..2..1 countdown on the last frame ---
    for i in [3, 2, 1, "GO"]:
        overlay = last_frame.copy()

        # --- Title box (reuse your existing title drawing code if needed) ---
        font = cv2.FONT_HERSHEY_SIMPLEX
        font_scale_title = 1.2
        thickness_title = 3
        text_size_title, baseline_title = cv2.getTextSize(label, font, font_scale_title, thickness_title)
        text_width_title, text_height_title = text_size_title
        center_x = overlay.shape[1] // 2
        text_x_title = center_x - text_width_title // 2
        text_y_title = 60

        top_left_title = (text_x_title - 10, text_y_title - text_height_title - 10)
        bottom_right_title = (text_x_title + text_width_title + 10, text_y_title + baseline_title + 10)
        cv2.rectangle(overlay, top_left_title, bottom_right_title, (255, 255, 255), -1)
        cv2.rectangle(overlay, top_left_title, bottom_right_title, (0, 0, 0), 2)
        cv2.putText(overlay, label, (text_x_title, text_y_title), font, font_scale_title, (0, 0, 0), thickness_title)

        # --- Countdown just below title ---
        font_scale_countdown = 2.0
        thickness_countdown = 4
        countdown_text = str(i)
        text_size, baseline = cv2.getTextSize(countdown_text, font, font_scale_countdown, thickness_countdown)
        text_width, text_height = text_size

        text_y = text_y_title + 80  # adjust spacing between title and countdown
        text_x = center_x - text_width // 2

        top_left = (text_x - 10, text_y - text_height - 10)
        bottom_right = (text_x + text_width + 10, text_y + baseline + 10)
        cv2.rectangle(overlay, top_left, bottom_right, (255, 255, 255), -1)
        cv2.rectangle(overlay, top_left, bottom_right, (0, 0, 0), 2)
        cv2.putText(overlay, countdown_text, (text_x, text_y+10), font, font_scale_countdown, (0, 0, 0), thickness_countdown)
        
        elapsed = time.time() - session_start
        progress = min(elapsed / total_duration, 1.0)
        draw_progress_bar(overlay, progress)

        cv2.imshow("Display", overlay)

        if i == "GO":
            send_gesture_classification(gesture_index + 1)

        if cv2.waitKey(1000) & 0xFF == ord('q'):
            exit(0)

    # --- Hold last frame for 2 seconds ---
    elapsed = time.time() - session_start
    progress = min(elapsed / total_duration, 1.0)
    draw_progress_bar(last_frame, progress)
    
    cv2.imshow("Display", last_frame)
    if cv2.waitKey(1000) & 0xFF == ord('q'):
        exit(0)

    # Do NOT destroy the window here — reused across calls

def play_balanced_videos_for(duration):
    start_time = time.time()
    while time.time() - start_time < duration:
        video_path = get_least_played_video()
        gesture_index = video_list.index(video_path)
        # Record the timestamp when the video is played
        play_order.append((video_path, int(time.time())))

        print(f"[PLAY] {os.path.basename(video_path)} (index: {gesture_index + 1})")
        play_video_then_countdown(video_path, gesture_index)

        if time.time() - start_time >= duration:
            break
        
def show_break(duration):
    def put_centered_text(img, text, y, font_scale=1.5, thickness=2, color=(0, 0, 0)):
        font = cv2.FONT_HERSHEY_SIMPLEX
        text_size, _ = cv2.getTextSize(text, font, font_scale, thickness)
        text_x = (img.shape[1] - text_size[0]) // 2
        cv2.putText(img, text, (text_x, y), font, font_scale, color, thickness)

    # Use higher resolution for better text quality
    frame_height, frame_width = 720, 720
    start = time.time()

    while time.time() - start < duration:
        remaining = math.ceil(duration - (time.time() - start))

        frame = np.full((frame_height, frame_width, 3), 230, dtype=np.uint8)  # Light gray

        put_centered_text(frame, 'Break Time', y=300, font_scale=2.5, thickness=5, color=(0, 0, 255))
        put_centered_text(frame, f'Resumes in: {remaining} s', y=450, font_scale=1.5, thickness=2)

        cv2.imshow("Display", frame)
        if cv2.waitKey(1000) & 0xFF == ord('q'):
            exit(0)

def draw_progress_bar(frame, progress, max_width=200, height=20):
    """
    Draws a progress bar at the top-right of the given frame.
    `progress` should be a float between 0 and 1.
    """
    h, w, _ = frame.shape
    x_start = w - max_width - 30
    y_start = h - height - 30
    
    # Outline
    cv2.rectangle(frame, (x_start, y_start), (x_start + max_width, y_start + height), (0, 0, 0), 2)

    # Fill
    fill_width = int(progress * max_width)
    cv2.rectangle(frame, (x_start, y_start), (x_start + fill_width, y_start + height), (0, 128, 0), -1)

def show_instructions():
    frame = np.full((800, 1000, 3), 245, dtype=np.uint8)  # soft gray background
    font = cv2.FONT_HERSHEY_SIMPLEX

    instructions = [
        "Welcome to the Hand Gesture Practice Session!",
        "",
        "You will see short videos demonstrating hand gestures.",
        "Each gesture will end with a countdown (3..2..1..GO).",
        "After 'GO' appears, perform the gesture yourself.",
        "",
        "Make sure your hand is in the correct starting position",
        "before performing the act.",
        "There will be 2 min breaks after each 2 minute set.",
        "",
        "Press 'q' at any time to quit.",
        "Press ENTER to begin..."
    ]

    y = 100
    for line in instructions:
        text_size, _ = cv2.getTextSize(line, font, 1, 2)
        x = (frame.shape[1] - text_size[0]) // 2
        cv2.putText(frame, line, (x, y), font, 1, (0, 0, 0), 2)
        y += 60

    cv2.imshow("Display", frame)
    while True:
        key = cv2.waitKey(0) & 0xFF
        if key == ord('\r') or key == 13:  # Enter key on Windows
            break
        elif key == ord('q'):
            exit(0)

# --- MAIN LOOP ---
show_instructions()

session_start = time.time()
cycle_count = 0

while time.time() - session_start < total_duration:
    play_balanced_videos_for(cycle_duration)
    if (time.time() - session_start > total_duration):
        break
    print("[BREAK] Taking a break...")
    #Sending a break classification
    send_gesture_classification(15)
    show_break(break_duration)

print("=== Session Complete ===")
print("Video play counts:")
for video, count in play_counts.items():
    print(f"{os.path.basename(video)}: {count}")

filename = "test"
csv_path = os.path.join(script_dir, f"{filename}.csv")

with open(csv_path, mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(["Timestamp", "Video Label", "Filename", "Class Index"])

    # Store the time each video was played
    # We'll need to track timestamps during play_balanced_videos_for
    for entry in play_order:
        # entry will be a tuple (path, timestamp) after modification
        path, timestamp = entry if isinstance(entry, tuple) else (entry, None)
        label = gesture_labels.get(os.path.basename(path), os.path.basename(path))
        class_index = video_list.index(path)  # Get index from original list
        writer.writerow([timestamp if timestamp is not None else '', label, os.path.basename(path), class_index + 1])

print(f"Play order saved to {csv_path}")