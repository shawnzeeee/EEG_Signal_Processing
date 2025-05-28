import cv2
import time
import random
import numpy as np
import os

# --- Configuration ---
video_files = ["GestureVideos\WIN_20250528_08_45_15_Pro.mp4", "video2.mp4", "video3.mp4"]  # Add more short videos
work_window = 2 * 60  # 2 minutes
break_window = 2 * 60  # 2 minutes
total_session = 15 * 60  # 15 minutes

def play_video(video_path):
    cap = cv2.VideoCapture(video_path)
    while cap.isOpened():
        ret, frame = cap.read()
        if not ret:
            break  # End of video
        cv2.imshow("Video", frame)
        if cv2.waitKey(30) & 0xFF == ord('q'):
            cap.release()
            cv2.destroyAllWindows()
            exit(0)
    cap.release()
    cv2.destroyAllWindows()

def run_video_block(duration_seconds):
    start = time.time()
    while time.time() - start < duration_seconds:
        vid = random.choice(video_files)
        print(f"Playing: {vid}")
        play_video(vid)

def show_break(duration_seconds):
    print("=== BREAK ===")
    break_start = time.time()
    while time.time() - break_start < duration_seconds:
        frame = 255 * np.ones((400, 600, 3), dtype=np.uint8)
        cv2.putText(frame, 'Break Time', (120, 200), cv2.FONT_HERSHEY_SIMPLEX,
                    1.5, (0, 0, 0), 4)
        cv2.imshow("Break", frame)
        if cv2.waitKey(1000) & 0xFF == ord('q'):
            break
    cv2.destroyAllWindows()

# --- Main Loop ---
session_start = time.time()
while time.time() - session_start < total_session:
    # Two 2-minute blocks of random videos
    run_video_block(2 * 60)
    run_video_block(2 * 60)

    # One 2-minute break
    show_break(2 * 60)

print("=== Session complete ===")
