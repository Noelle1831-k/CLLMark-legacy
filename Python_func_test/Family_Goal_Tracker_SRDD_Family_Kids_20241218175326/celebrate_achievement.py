def celebrate_achievement(self):
        completed_goals = [g for g in self.goals if g.is_completed()]
        for goal in completed_goals:
            print(f"Congratulations! Goal '{goal.title}' completed.")