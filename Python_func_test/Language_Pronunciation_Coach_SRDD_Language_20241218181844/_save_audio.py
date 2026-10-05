def _save_audio(self, file_path):
        with wave.open(file_path, 'wb') as wf:
            wf.setnchannels(self.channels)
            wf.setsampwidth(2)
            wf.setframerate(self.sample_rate)
            wf.writeframes(np.concatenate(self.frames).astype(np.int16).tobytes())