def save_audio(self, file_path, audio_data):
        '''
        Save the processed audio data to a file.
        Parameters:
        - file_path: Path to save the audio file.
        - audio_data: A tuple containing the audio array and sample rate.
        '''
        y_stretched, sample_rate = audio_data
        sf.write(file_path, y_stretched, sample_rate)