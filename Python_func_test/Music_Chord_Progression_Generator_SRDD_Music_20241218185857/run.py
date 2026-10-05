def run(self):
        user_input = self.user_interface.get_user_input()
        if self.key_validator.validate_key(user_input['key']):
            mood_chords = self.mood_analyzer.analyze_mood(user_input['mood'])
            progressions = self.chord_generator.generate_progression(user_input['key'], mood_chords)
            self.user_interface.display_progressions(progressions)
            self.file_manager.save_progression(progressions, "progression.txt")
            self.file_manager.export_progression(progressions, "pdf")
        else:
            print("Invalid key entered. Please try again.")