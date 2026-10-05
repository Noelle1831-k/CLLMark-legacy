def get_goals(self, user_profile):
        return self.goals.get(user_profile, [])