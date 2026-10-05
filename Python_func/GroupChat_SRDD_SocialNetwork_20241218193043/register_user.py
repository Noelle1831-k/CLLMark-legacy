def register_user(self, username):
        user = User(username)
        self.users.append(user)
        return user