def get_sleep_data(self, user):
        return self.sleep_data.get(user.name, [])