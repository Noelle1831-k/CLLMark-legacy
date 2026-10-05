def start_recording(self):
        self.is_recording = True
        self.frames = []
        self.recording = sd.InputStream(samplerate=self.sample_rate, channels=self.channels, callback=self._callback)
        self.recording.start()