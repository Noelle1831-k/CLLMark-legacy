def declare_winner(self):
        if self.participants:
            winner = self.participants[0]  # Simplified winner selection
            winner.tournaments_won += 1
            print(f"{winner.name} has won the tournament {self.name}!")