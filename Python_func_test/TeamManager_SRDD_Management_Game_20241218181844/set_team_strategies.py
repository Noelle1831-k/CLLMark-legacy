def set_team_strategies(self):
        for team in self.teams:
            strategy = input(f"Set strategy for {team.name} (e.g., Offensive, Defensive, Balanced): ")
            team.set_strategy(strategy)