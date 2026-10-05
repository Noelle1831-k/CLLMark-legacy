def extract_features(self, audio_data):
        # Extract features such as chroma, tempo, etc.
        try:
            chroma = librosa.feature.chroma_stft(y=audio_data)
            tempo, _ = librosa.beat.beat_track(y=audio_data)
            return {'chroma': chroma, 'tempo': tempo}
        except Exception as e:
            print(f"Error extracting features: {e}")
            return {'chroma': np.array([]), 'tempo': 0}