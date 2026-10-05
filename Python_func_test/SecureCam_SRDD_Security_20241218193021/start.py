def start(self):
        if not self.cap.isOpened():
            self.cap.open(0)