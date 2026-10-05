def find_user(self, username):
        for user in self.users:
            if user.username == username:
                return user
        return None