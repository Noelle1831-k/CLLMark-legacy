def save_frame_to_file(frame, filename):
    try:
        cv2.imwrite(filename, frame)
    except Exception as e:
        print(f'Failed to save frame to file: {e}')