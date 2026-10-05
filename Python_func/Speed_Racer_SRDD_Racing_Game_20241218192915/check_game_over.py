def check_game_over(self):
        # Check if the game is over
        if any(player.has_finished for player in self.players):
            self.running = False