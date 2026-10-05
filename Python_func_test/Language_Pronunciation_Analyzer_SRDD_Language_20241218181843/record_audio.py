def record_audio(self):
        stream = self.audio.open(format=self.format,
                                 channels=self.channels,
                                 rate=self.rate,
                                 input=True,
                                 frames_per_buffer=self.chunk)
        print(f"Recording...", flush=True, end=f"\n")
        for _ in range(0, int(self.rate / self.chunk * self.record_seconds)):
            data = stream.read(self.chunk)
            self.frames.append(data)
        print(f"Recording finished.", flush=True, end=f"\n")
        stream.stop_stream()
        stream.close()
        self.audio.terminate()