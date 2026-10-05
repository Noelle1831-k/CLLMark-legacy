def get_user_intake_summary(self, user):
        if user.name in self.users:
            return self.users[user.name]["water_intake"].get_intake_summary()
        return {}