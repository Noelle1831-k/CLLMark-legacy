def save_audio(self, audio_data, output_path):
        '''
        Saves the processed audio data to the specified output path.
        '''
        try:
            y, sr = audio_data
            sf.write(output_path, y, sr)
        except Exception as e:
            print(f"Error saving audio file: {e}")