def record_audio(self, duration=5):
        '''
        Records audio for a given duration.
        '''
        p = pyaudio.PyAudio()
        stream = p.open(format=pyaudio.paInt16, channels=1, rate=self.rate, input=True, frames_per_buffer=self.chunk)
        frames = []
        print("Recording...")
        for _ in range(0, int(self.rate / self.chunk * duration)):
            data = stream.read(self.chunk)
            frames.append(data)
        print("Recording complete.")
        stream.stop_stream()
        stream.close()
        p.terminate()
        audio_data = b''.join(frames)
        return np.frombuffer(audio_data, dtype=np.int16)