def start_tracking(self):
        self.is_tracking = True
        print("Tracking started.")
        self.tracking_thread = threading.Thread(target=self._track)
        self.tracking_thread.start()