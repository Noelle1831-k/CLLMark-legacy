def display_goals(self, user_profile):
        goals = self.get_goals(user_profile)
        for goal in goals:
            print(f"Goal: {goal[0]} by {goal[1]}")