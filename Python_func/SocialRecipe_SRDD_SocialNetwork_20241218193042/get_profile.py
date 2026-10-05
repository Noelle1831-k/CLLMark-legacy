def get_profile(self, email):
        if email not in self.users:
            raise ValueError("User does not exist.")
        return self.users[email]