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

cycle_duration = 2 * 60   # 2 minutes per video session
break_duration = 2 * 60   # 2-minute break
total_duration = 15 * 60  # total session time

# --- HELPER FUNCTIONS ---
def send_gesture_classification(gesture_code):
    """Writes an integer gesture classification (0 to 5) into shared memory."""
    shm.seek(0)
    shm.write(struct.pack('i', gesture_code))

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
        cv2.putText(overlay, str(i), (x, y), cv2.FONT_HERSHEY_SIMPLEX,
                    3, (0, 0, 255), 6)
        cv2.imshow("Display", overlay)

        if i == "GO":
            send_gesture_classification(gesture_index)  # You pass index into the function

        if cv2.waitKey(1000) & 0xFF == ord('q'):
            exit(0)

    # --- Hold last frame for 2 seconds ---
    cv2.imshow("Display", last_frame)
    if cv2.waitKey(1000) & 0xFF == ord('q'):
        exit(0)

    # Do NOT destroy the window here — reused across calls

def play_open_close_alternating(duration, pairs):
    start_time = time.time()
    while time.time() - start_time < duration:
        index = random.randint(0, 5)  # Or len(video_list) - 1
        video_path = video_list[index]
        
        print(f"[PLAY] {os.path.basename(video_path)}")
        play_video_then_countdown(video_path, index)

        if time.time() - start_time >= duration:
            break

def show_break(duration):
    start = time.time()
    while time.time() - start < duration:
        remaining = int(duration - (time.time() - start))

        frame = 255 * np.ones((400, 600, 3), dtype=np.uint8)
        
        # Draw "Break Time"
        cv2.putText(frame, 'Break Time', (120, 150), cv2.FONT_HERSHEY_SIMPLEX,
                    1.5, (0, 0, 255), 4)

        # Draw countdown timer
        countdown_text = f"Resumes in: {remaining} s"
        cv2.putText(frame, countdown_text, (100, 250), cv2.FONT_HERSHEY_SIMPLEX,
                    1, (0, 0, 0), 2)

        cv2.imshow("Display", frame)
        if cv2.waitKey(2000) & 0xFF == ord('q'):
            exit(0)
        
# --- MAIN LOOP ---
session_start = time.time()
cycle_count = 0

while time.time() - session_start < total_duration:
    # Alternate open-close videos for 2 minutes
    play_open_close_alternating(cycle_duration, video_list)
    print("[BREAK] Taking a 2-minute break...")
    show_break(break_duration)

print("=== Session Complete ===")
