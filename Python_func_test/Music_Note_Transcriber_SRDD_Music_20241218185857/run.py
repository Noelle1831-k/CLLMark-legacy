def run(self):
        '''
        Main execution method for the transcription process.
        '''
        self.ui_handler.display_interface()
        audio_data = self.audio_processor.record_audio()
        processed_audio = self.audio_processor.preprocess_audio(audio_data)
        frequency_data = self.note_recognizer.extract_frequency_spectrum(processed_audio)
        notes = self.note_recognizer.map_frequencies_to_notes(frequency_data)
        self.ui_handler.show_results(notes)