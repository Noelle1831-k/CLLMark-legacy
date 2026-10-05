def load_file(self, file_path):
        '''
        Loads the music file and returns the audio data and sample rate.
        '''
        try:
            data, sr = librosa.load(file_path, sr=None)  # Preserve original sample rate
            print(f"Successfully loaded file: {file_path}")
            return data, sr
        except Exception as e:
            print(f"Error loading file: {e}")
            return None