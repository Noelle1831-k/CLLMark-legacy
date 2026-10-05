def log_water_intake(self, user, amount):
        if user.name in self.users:
            time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            self.users[user.name]["water_intake"].add_intake(amount, time)