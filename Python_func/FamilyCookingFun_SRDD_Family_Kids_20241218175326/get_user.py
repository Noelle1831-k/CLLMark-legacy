def get_user(self, user_name):
        for user in self.users:
            if user.name == user_name:
                return user
        return None