def load_audio(self, filename):
        wf = wave.open(filename, 'rb')
        self.audio_data = np.frombuffer(wf.readframes(wf.getnframes()), dtype=np.int16)
        self.audio_rate = wf.getframerate()
        wf.close()