def load_audio(self, file_path):
        # Load audio file using librosa
        try:
            audio_data, sr = librosa.load(file_path, sr=None)
            return audio_data
        except Exception as e:
            print(f"Error loading audio file: {e}")
            return np.array([])