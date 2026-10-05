def run(self):
        # Display a welcome message to the user
        self.user_interface.display_message("Welcome to the Music Tempo Adjuster!")
        # Get user input for the file path and target tempo
        file_path, target_tempo = self.user_interface.get_user_input()
        # Load the audio data from the specified file path
        audio_data = self.audio_processor.load_audio(file_path)
        # Adjust the tempo of the loaded audio data
        adjusted_audio = self.audio_processor.adjust_tempo(audio_data, target_tempo)
        # Save the adjusted audio data to an output file
        self.audio_processor.save_audio("output.wav", adjusted_audio)
        # Notify the user that the tempo adjustment is complete
        self.user_interface.display_message("Tempo adjustment complete. File saved as 'output.wav'.")