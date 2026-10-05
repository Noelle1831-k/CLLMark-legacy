def start_game(self):
        self.track.load_track()
        while self.running:
            self.handle_input()
            self.update()
            self.render()