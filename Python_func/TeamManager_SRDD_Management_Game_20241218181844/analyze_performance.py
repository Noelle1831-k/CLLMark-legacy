def analyze_performance(self):
        print(f"Match result: {self.result}")
        if self.result != "Draw":
            winning_team = self.team1 if self.result == self.team1.name else self.team2
            losing_team = self.team2 if self.result == self.team1.name else self.team1
            print(f"{winning_team.name} wins against {losing_team.name}")
        else:
            print("The match ended in a draw.")