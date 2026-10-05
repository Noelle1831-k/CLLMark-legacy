def record_audio(self):
        stream = self.audio.open(format=self.format,
                                 channels=self.channels,
                                 rate=self.rate,
                                 input=True,
                                 frames_per_buffer=self.chunk)
        print("Recording...")
        for _ in range(0, int(self.rate / self.chunk * self.record_seconds)):
            data = stream.read(self.chunk)
            self.frames.append(data)
        print("Recording finished.")
        stream.stop_stream()
        stream.close()
        self.audio.terminate()