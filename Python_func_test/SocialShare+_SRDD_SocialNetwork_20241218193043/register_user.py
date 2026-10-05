def register_user(self, username):
        if username not in self.users:
            user = User(username)
            self.users[username] = user
            return user
        return None