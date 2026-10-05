def load_audio(self, file_path):
        '''
        Loads an audio file from the specified path.
        '''
        try:
            audio_data, sr = librosa.load(file_path, sr=None)
            return audio_data, sr
        except Exception as e:
            print(f"Error loading audio file: {e}")
            return None