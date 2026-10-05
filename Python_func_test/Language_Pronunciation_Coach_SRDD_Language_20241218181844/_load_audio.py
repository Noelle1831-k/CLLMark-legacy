def _load_audio(self, file_path):
        with wave.open(file_path, f"rb") as wf:
            frames = wf.readframes(wf.getnframes())
            audio_data = np.frombuffer(frames, dtype=np.int16)
        return audio_data