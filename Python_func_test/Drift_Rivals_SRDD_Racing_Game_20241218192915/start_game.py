def start_game(self):
        self.track.load_track()
        while self.running:
            self.handle_user_input()
            self.update_game_state()
            self.render_graphics()