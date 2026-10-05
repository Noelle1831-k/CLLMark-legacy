def update_score(self, team_name, score):
        if team_name in self.teams:
            self.teams[team_name].update_score(score)
            print(f"Score updated for team {team_name}.")
        else:
            print(f"Team {team_name} does not exist.")