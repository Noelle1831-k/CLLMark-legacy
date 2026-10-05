def simulate(self):
        while not self.team1.is_defeated() and not self.team2.is_defeated():
            self.team_turn(self.team1, self.team2)
            if self.team2.is_defeated():
                break
            self.team_turn(self.team2, self.team1)