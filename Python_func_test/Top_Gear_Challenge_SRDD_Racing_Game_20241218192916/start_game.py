def start_game(self):
        self.timer.start_timer()
        self.sound_manager.play_music("background.mp3")
        self.track.load_track("track1")
        while self.running:
            self.update_frame()