def create_profile(self, name, email, bio="", location=""):
        self.profile = {
            "name": name,
            "email": email,
            "bio": bio,
            "location": location
        }