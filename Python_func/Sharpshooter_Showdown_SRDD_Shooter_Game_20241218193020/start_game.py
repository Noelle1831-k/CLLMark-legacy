def start_game(self):
        print("Welcome to Sharpshooter Showdown!")
        self.levels.load_level(self.current_level)
        self.player.reset_score()
        self.game_loop()