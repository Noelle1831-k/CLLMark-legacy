def start(self):
        self.initialize_game()
        while self.running:
            self.game_loop()