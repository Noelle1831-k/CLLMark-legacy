def update_profile(self, email, updates):
        if email not in self.users:
            raise ValueError("User does not exist.")
        self.users[email].update(updates)
        print(f"Profile updated for {email}.")