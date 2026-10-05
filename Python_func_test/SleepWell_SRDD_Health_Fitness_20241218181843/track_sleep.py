def track_sleep(self, user, sleep_hours):
        if user.name not in self.sleep_data:
            self.sleep_data[user.name] = list()
        self.sleep_data[user.name].append(sleep_hours)