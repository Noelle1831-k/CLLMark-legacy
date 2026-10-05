def load_audio(self, file_path):
        '''
        Loads audio data from a file path.
        Parameters:
            file_path (str): Path to the audio file.
        Returns:
            y (np.ndarray): Audio time series.
            sr (int): Sampling rate of the audio file.
        '''
        y, sr = librosa.load(file_path, sr=None)
        self.sample_rate = sr
        self.audio_data = y
        return y, sr