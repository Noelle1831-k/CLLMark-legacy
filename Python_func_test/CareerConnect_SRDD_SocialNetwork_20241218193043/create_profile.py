def create_profile(self):
        self.profile = {
            "name": self.name,
            "role": self.role,
            "industry": self.industry
        }
        print(f"Profile created for {self.name}", flush=True)