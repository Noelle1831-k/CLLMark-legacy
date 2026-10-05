def stop_tracking(self):
        self.is_tracking = False
        if self.tracking_thread is not None:
            self.tracking_thread.join()
        print("Tracking stopped.")