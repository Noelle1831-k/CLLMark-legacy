def get_user_intake(self, user):
        if user.name in self.users:
            return self.users[user.name]["water_intake"].get_daily_intake()
        return 0