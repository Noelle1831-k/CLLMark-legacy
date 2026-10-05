def add_user(self, user):
        if user.name not in self.users:
            self.users[user.name] = {
                'user': user,
                'water_intake': WaterIntake()
            }