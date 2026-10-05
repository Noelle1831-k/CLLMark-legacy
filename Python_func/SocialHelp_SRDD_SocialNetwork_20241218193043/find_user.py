def find_user(self, name):
        for user in self.users:
            if user.name == name:
                return user
        return None