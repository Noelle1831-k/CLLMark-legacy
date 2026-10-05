def create_profile(self):
        self.profile = {"name": self.name}
        self.db.save_user(self.profile)
        print(f"Profile created for {self.name}")