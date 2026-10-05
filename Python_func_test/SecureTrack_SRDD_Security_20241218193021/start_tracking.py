def start_tracking(self):
        self.is_tracking = True
        print(f'Tracking started.', flush=True, end=f'\n')
        self.tracking_thread = threading.Thread(target=self._track)
        self.tracking_thread.start()