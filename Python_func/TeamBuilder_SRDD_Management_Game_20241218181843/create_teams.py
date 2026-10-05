def create_teams(self):
        for i in range(2):
            team = Team(f"Team {i+1}")
            for _ in range(5):
                player = self.scout.scout_players()
                team.add_player(player)
            self.teams.append(team)