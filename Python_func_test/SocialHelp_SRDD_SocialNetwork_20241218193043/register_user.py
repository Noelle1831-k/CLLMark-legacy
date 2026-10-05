def register_user(self, name):
        user = User(name)
        self.users.append(user)
        return user