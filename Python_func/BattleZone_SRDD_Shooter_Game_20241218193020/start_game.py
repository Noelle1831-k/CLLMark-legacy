def start_game(self):
        self.running = True
        while self.running:
            self.update_game_state()