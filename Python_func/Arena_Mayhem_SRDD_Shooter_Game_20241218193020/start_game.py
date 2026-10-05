def start_game(self):
        self.is_running = True
        self.setup_players()
        self.arena.generate_layout()
        self.arena.place_random_powerups(self.powerups)
        while self.is_running:
            self.update_game_state()
            self.check_game_over()