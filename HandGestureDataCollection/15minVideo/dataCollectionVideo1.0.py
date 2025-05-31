import cv2
import time
import random
import numpy as np
import os

script_dir = os.path.dirname(os.path.abspath(__file__))

# --- CONFIG ---
open_close_pairs = { 
         os.path.join(script_dir,"GestureVideos/index_close.mp4")       : os.path.join(script_dir,"GestureVideos/index_open.mp4"), 
         os.path.join(script_dir,"GestureVideos/middle_close.mp4")      : os.path.join(script_dir,"GestureVideos/middle_open.mp4"), 
         os.path.join(script_dir,"GestureVideos/pinky_ring_close.mp4")  : os.path.join(script_dir,"GestureVideos/pinky_ring_open.mp4"), 
         os.path.join(script_dir,"GestureVideos/1thumb_close.mp4")      : os.path.join(script_dir,"GestureVideos/1thumb_open.mp4"), 
}

cycle_duration = 2 * 60   # 2 minutes per video session
break_duration = 2 * 60   # 2-minute break
total_duration = 15 * 60  # total session time

# --- HELPER FUNCTIONS ---
def play_video_then_countdown(path):
    cap = cv2.VideoCapture(path)
    if not cap.isOpened():
        print(f"Cannot open: {path}")
        return

    frame_rate = cap.get(cv2.CAP_PROP_FPS) or 30
    last_frame = None

    # --- Play the video and remember the last frame ---
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        last_frame = frame.copy()
        cv2.imshow("Display", frame)
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
        open_vid = random.choice(list(pairs.keys()))
        close_vid = pairs[open_vid]

        print(f"[OPEN] Playing: {open_vid}")
        play_video_then_countdown(open_vid)
        
        if time.time() - start_time >= duration:
            break

        time.sleep(3)
        print(f"[CLOSE] Playing: {close_vid}")
        play_video_then_countdown(close_vid)

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
        if cv2.waitKey(1000) & 0xFF == ord('q'):
            exit(0)
        
# --- MAIN LOOP ---
session_start = time.time()
cycle_count = 0

while time.time() - session_start < total_duration:
    # Alternate open-close videos for 2 minutes
    play_open_close_alternating(cycle_duration, open_close_pairs)
    print("[BREAK] Taking a 2-minute break...")
    show_break(break_duration)

print("=== Session Complete ===")
