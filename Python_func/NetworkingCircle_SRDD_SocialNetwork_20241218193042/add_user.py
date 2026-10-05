def add_user(self, user):
        if user not in self.users:
            self.users.append(user)