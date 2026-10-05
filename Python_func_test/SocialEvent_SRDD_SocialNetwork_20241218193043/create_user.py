def create_user(self, username, email):
        user = User(username, email)
        self.users.append(user)
        return user