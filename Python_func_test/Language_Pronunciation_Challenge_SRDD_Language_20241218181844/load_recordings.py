def load_recordings(self):
        self.recordings = [f'{self.language}_recording_{i}' for i in range(1, 6)]