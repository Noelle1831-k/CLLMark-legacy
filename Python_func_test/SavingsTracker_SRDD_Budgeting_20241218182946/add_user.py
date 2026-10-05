def add_user(self, name):
        if name not in self.users:
            self.users[name] = User(name)