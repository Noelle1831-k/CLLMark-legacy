def update_profile(self, email, name=None, title=None):
        if email in self.profiles:
            if name:
                self.profiles[email]["name"] = name
            if title:
                self.profiles[email]["title"] = title
            print(f"Profile updated for {email}.")
        else:
            print("Profile not found.")