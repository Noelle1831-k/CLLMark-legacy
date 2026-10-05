def update_leaderboard(self, completed_chores):
        for chore, user in completed_chores:
            if user.name not in self.scores:
                self.scores[user.name] = 0
            self.scores[user.name] += self.chore_manager.get_chore_points(chore)