def login_user(self, username):
        if username not in self.users:
            raise ValueError(f'User not found.')
        return self.users[username]