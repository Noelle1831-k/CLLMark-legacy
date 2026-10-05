def create_profile(self):
        self.profile = {"user_id": self.user_id, "name": self.name, "email": self.email}
        self.db.add_user(self)
        print(f"Profile created for {self.name}")