def add_user(self, user):
        if user.location not in self.user_locations:
            self.user_locations[user.location] = []
        self.user_locations[user.location].append(user)