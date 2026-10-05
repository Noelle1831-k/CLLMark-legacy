def select_file(self):
        if self.file_list:
            selected_file = self.file_list[self.selected_file_index]
            self.audio_processor.load_audio(selected_file)
            self.file_selection_active = False