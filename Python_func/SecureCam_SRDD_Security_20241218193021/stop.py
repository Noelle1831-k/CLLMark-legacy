def stop(self):
        if self.cap.isOpened():
            self.cap.release()