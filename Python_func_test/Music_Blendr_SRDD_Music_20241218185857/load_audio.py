def load_audio(self, file_path):
        if os.path.exists(file_path):
            track = self._simulate_audio_loading(file_path)
            self.tracks.append(track)
        else:
            print(f"File {file_path} not found.")