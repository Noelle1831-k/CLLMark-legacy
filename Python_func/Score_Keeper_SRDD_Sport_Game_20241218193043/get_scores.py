def get_scores(self):
        return {name: team.score for name, team in self.teams.items()}