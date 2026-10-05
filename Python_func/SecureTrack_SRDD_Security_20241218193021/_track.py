def _track(self):
        while self.is_tracking:
            try:
                data_point = self._generate_data_point()
                self.tracking_data.append(data_point)
                time.sleep(1)
            except Exception as e:
                print(f"Error during tracking: {e}")