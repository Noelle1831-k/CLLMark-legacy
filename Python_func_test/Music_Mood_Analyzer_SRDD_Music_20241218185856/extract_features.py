def extract_features(self, audio_data):
        '''
        Extract audio features like tempo, key, and instrumentation.
        '''
        if audio_data is None:
            return None
        try:
            tempo, _ = librosa.beat.beat_track(y=audio_data)
            chroma = librosa.feature.chroma_stft(y=audio_data)
            key = chroma.argmax(axis=0).mean()
            instrumentation = librosa.feature.spectral_contrast(y=audio_data).mean(axis=1)
            return {'tempo': tempo, 'key': key, 'instrumentation': instrumentation}
        except Exception as e:
            print(f"Error extracting features: {e}")
            return None