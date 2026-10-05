def import_tracks(self):
        file_paths = self.ui.get_file_paths()
        for path in file_paths:
            self.audio_manager.load_audio(path)