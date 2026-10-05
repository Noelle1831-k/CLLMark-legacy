def update_leaderboard(self, players, mission_success):
        for player in players:
            if player.name not in self.scores:
                self.scores[player.name] = 0
            if mission_success:
                self.scores[player.name] += 100
            print(f"Updated leaderboard: {player.name} - {self.scores[player.name]} points")