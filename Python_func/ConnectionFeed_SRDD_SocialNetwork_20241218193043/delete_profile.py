def delete_profile(self, email):
        if email in self.users:
            del self.users[email]
            print("Profile deleted.")
        else:
            print("User not found.")