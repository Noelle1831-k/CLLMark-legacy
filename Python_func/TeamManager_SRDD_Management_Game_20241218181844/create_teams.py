def create_teams(self):
        for i in range(4):
            self.teams.append(team.Team(f"Team {i+1}"))