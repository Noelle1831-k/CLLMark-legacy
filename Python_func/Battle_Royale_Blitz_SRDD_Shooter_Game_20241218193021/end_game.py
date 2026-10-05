def end_game(self):
        self.is_running = False
        winner = self.determine_winner()
        print(f"Game over! Winner: {winner.character.name}")