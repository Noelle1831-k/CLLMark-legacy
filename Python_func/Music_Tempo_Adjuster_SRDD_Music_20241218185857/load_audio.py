def load_audio(self, file_path):
        '''
        Load audio data from a file.
        Parameters:
        - file_path: Path to the audio file.
        Returns:
        - A tuple containing the audio array and sample rate.
        '''
        audio_data, sample_rate = librosa.load(file_path, sr=None)
        return audio_data, sample_rate