def get_user(self, email):
        for user in self.users:
            if user.email == email:
                return user
        return None