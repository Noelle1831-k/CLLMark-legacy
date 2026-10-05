def update_standings(self, results):
        sorted_teams = sorted(results, key=results.get, reverse=True)
        points_distribution = [10, 8, 6, 4, 2]
        for i, team_name in enumerate(sorted_teams):
            self.standings[team_name] += points_distribution[i]