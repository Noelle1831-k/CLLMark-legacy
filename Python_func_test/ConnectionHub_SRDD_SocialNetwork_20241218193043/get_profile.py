def get_profile(self, email):
        return self.profiles.get(email, "Profile not found.")