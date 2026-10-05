def toggle_file_selection(self):
        self.file_selection_active = not self.file_selection_active
        if self.file_selection_active:
            self.file_list = [f for f in os.listdir('.') if f.endswith(('.mp3', '.wav'))]
            self.selected_file_index = 0