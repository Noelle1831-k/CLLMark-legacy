def add_user(self, user):
        if isinstance(user, User):
            self.users.append(user)