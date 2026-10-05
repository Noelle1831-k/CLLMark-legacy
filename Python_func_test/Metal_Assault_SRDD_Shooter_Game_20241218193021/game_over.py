def game_over(self):
        print("Game Over! Restarting...")
        self.running = False
        self.start_game()  # Restart the game