import cv2
import time
import random
import numpy as np

# --- CONFIG ---
open_close_pairs = { 
        "15minVideo/GestureVideos/index_close.mp4":"15minVideo/GestureVideos/index_open.mp4", 
        "15minVideo/GestureVideos/middle_close.mp4":"15minVideo/GestureVideos/middle_open.mp4", 
        "15minVideo/GestureVideos/pinky_ring_close.mp4":"15minVideo/GestureVideos/pinky_ring_open.mp4", 
        "15minVideo/GestureVideos/1thumb_close.mp4":"15minVideo/GestureVideos/1thumb_open.mp4", 
}
cycle_duration = 2 * 60   # 2 minutes per video session
break_duration = 2 * 60   # 2-minute break
total_duration = 15 * 60  # total session time

# --- HELPER FUNCTIONS ---
def play_video(path):
    cap = cv2.VideoCapture(path)
    if not cap.isOpened():
        print(f"Cannot open: {path}")
        return
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        cv2.imshow("Video", frame)
        if cv2.waitKey(30) & 0xFF == ord('q'):
            exit(0)
    cap.release()
    cv2.destroyAllWindows()

def play_open_close_alternating(duration, pairs):
    start_time = time.time()
    while time.time() - start_time < duration:
        open_vid = random.choice(list(pairs.keys()))
        close_vid = pairs[open_vid]

        print(f"[OPEN] Playing: {open_vid}")
        play_video(open_vid)
        if time.time() - start_time >= duration:
            break

        print(f"[CLOSE] Playing: {close_vid}")
        play_video(close_vid)

def show_break(duration):
    start = time.time()
    while time.time() - start < duration:
        frame = 255 * np.ones((400, 600, 3), dtype=np.uint8)
        cv2.putText(frame, 'Break Time', (120, 200), cv2.FONT_HERSHEY_SIMPLEX,
                    1.5, (0, 0, 255), 4)
        cv2.imshow("Break", frame)
        if cv2.waitKey(1000) & 0xFF == ord('q'):
            exit(0)
    cv2.destroyAllWindows()

# --- MAIN LOOP ---
session_start = time.time()
cycle_count = 0

while time.time() - session_start < total_duration:
    # Alternate open-close videos for 2 minutes
    play_open_close_alternating(cycle_duration, open_close_pairs)
    cycle_count += 1

    # Break after every 2 open-close blocks
    if cycle_count % 2 == 0:
        print("[BREAK] Taking a 2-minute break...")
        show_break(break_duration)

print("=== Session Complete ===")
