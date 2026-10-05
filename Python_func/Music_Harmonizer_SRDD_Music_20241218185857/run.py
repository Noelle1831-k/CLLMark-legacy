def run(self):
        self.ui_manager.display_welcome_message()
        music_file = self.file_uploader.upload_file()
        melody_data = self.melody_analyzer.analyze(music_file)
        harmony_style = self.ui_manager.select_harmony_style()
        harmony_level = self.ui_manager.adjust_harmony_level()
        harmonized_track = self.harmony_generator.generate_harmony(melody_data, harmony_style, harmony_level)
        self.ui_manager.preview_track(harmonized_track)
        self.file_uploader.save_file(harmonized_track)