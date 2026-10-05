def capture_frame(self):
        ret, frame = self.cap.read()
        if ret:
            return frame
        return None