def start_game(self):
        self.ui.display_menu()
        self.track.load_track()
        self.audio.play_music("background.mp3")
        while self.running:
            self.update()
            time.sleep(0.016)  # Simulate 60 FPS