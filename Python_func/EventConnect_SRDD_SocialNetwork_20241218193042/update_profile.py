def update_profile(self, name=None, email=None):
        if name:
            self.name = name
        if email:
            self.email = email
        self.profile = {"user_id": self.user_id, "name": self.name, "email": self.email}
        print(f"Profile updated for {self.name}")