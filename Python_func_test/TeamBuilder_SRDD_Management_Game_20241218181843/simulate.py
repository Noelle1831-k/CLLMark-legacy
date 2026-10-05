def simulate(self):
        score1 = self.team1.evaluate_team_strength()
        score2 = self.team2.evaluate_team_strength()
        if score1 > score2:
            return self.team1
        elif score2 > score1:
            return self.team2
        else:
            # Handle tie scenario
            return self.tie_breaker()