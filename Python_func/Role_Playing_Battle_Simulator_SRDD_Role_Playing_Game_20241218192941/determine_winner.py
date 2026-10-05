def determine_winner(self):
        if self.team1.is_defeated():
            return self.team2.name
        elif self.team2.is_defeated():
            return self.team1.name
        return "Draw"