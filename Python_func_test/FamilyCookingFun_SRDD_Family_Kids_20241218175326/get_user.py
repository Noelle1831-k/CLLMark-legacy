def get_user(self, user_name):
        for user in self.users:
            if user_name == user.name:
                return user
        return None