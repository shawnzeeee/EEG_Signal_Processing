import cv2
import time
import random
import numpy as np
import os
import mmap
import struct

script_dir = os.path.dirname(os.path.abspath(__file__))

SHARED_MEMORY_NAME = "Local\\GestureSharedMemory"
SHARED_MEMORY_SIZE = 256
shm = mmap.mmap(-1, SHARED_MEMORY_SIZE, SHARED_MEMORY_NAME, access=mmap.ACCESS_WRITE)

#classifications of hand gestures:
#Hand close     = 0
#Hand open      = 1
#Ok close       = 2
#Ok open        = 3
#Prong close    = 4
#Prong open     = 5

# --- CONFIG ---
video_list = [ 
         os.path.join(script_dir,"GestureVideos/Handclose2.mp4"),
         os.path.join(script_dir,"GestureVideos/Handopen2.mp4"), 
         os.path.join(script_dir,"GestureVideos/Okclose2.mp4"),
         os.path.join(script_dir,"GestureVideos/Okopen2.mp4"), 
         os.path.join(script_dir,"GestureVideos/Prongclose2.mp4"),
         os.path.join(script_dir,"GestureVideos/Prongopen2.mp4"), 
]

#for controlled randomness
play_counts = {path: 0 for path in video_list}

gesture_labels = {
    "Handopen2.mp4": "Open Hand",
    "Handclose2.mp4": "Close Hand",
    "Okopen2.mp4": "OK Sign (Open)",
    "Okclose2.mp4": "OK Sign (Close)",
    "Prongopen2.mp4": "Prong Gesture (Open)",
    "Prongclose2.mp4": "Prong Gesture (Close)",
}

cycle_duration = 2 * 60   # 2 minutes per video session
break_duration = 2 * 60   # 2-minute break
total_duration = 15 * 60  # total session time

# --- HELPER FUNCTIONS ---
def send_gesture_classification(gesture_code):
    """Writes an integer gesture classification (0 to 5) into shared memory."""
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

    frame_rate = 60
    last_frame = None
    cv2.namedWindow("Display", cv2.WINDOW_NORMAL)
    cv2.resizeWindow("Display", 1080, 1080)
    
    # --- Play the video and remember the last frame ---
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        last_frame = frame.copy()
        
        resized_frame = cv2.resize(frame, (1080, 1080))

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

        cv2.imshow("Display", overlay)

        if i == "GO":
            send_gesture_classification(gesture_index)

        if cv2.waitKey(1000) & 0xFF == ord('q'):
            exit(0)

    # --- Hold last frame for 2 seconds ---
    cv2.imshow("Display", last_frame)
    if cv2.waitKey(1000) & 0xFF == ord('q'):
        exit(0)

    # Do NOT destroy the window here — reused across calls

def play_balanced_videos_for(duration):
    start_time = time.time()
    while time.time() - start_time < duration:
        video_path = get_least_played_video()
        gesture_index = video_list.index(video_path)
        
        print(f"[PLAY] {os.path.basename(video_path)} (index: {gesture_index})")
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
    frame_height, frame_width = 800, 800
    start = time.time()

    while time.time() - start < duration:
        remaining = int(duration - (time.time() - start))

        frame = np.full((frame_height, frame_width, 3), 230, dtype=np.uint8)  # Light gray

        put_centered_text(frame, 'Break Time', y=300, font_scale=2.5, thickness=5, color=(0, 0, 255))
        put_centered_text(frame, f'Resumes in: {remaining} s', y=450, font_scale=1.5, thickness=2)

        cv2.imshow("Display", frame)
        if cv2.waitKey(1000) & 0xFF == ord('q'):
            exit(0)
        
# --- MAIN LOOP ---
session_start = time.time()
cycle_count = 0

while time.time() - session_start < total_duration:
    # Alternate open-close videos for 2 minutes
    play_balanced_videos_for(cycle_duration)
    print("[BREAK] Taking a 2-minute break...")
    show_break(break_duration)

print("=== Session Complete ===")
print("Video play counts:")
for video, count in play_counts.items():
    print(f"{os.path.basename(video)}: {count}")