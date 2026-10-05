def view_profile(self, email):
        if email in self.users:
            return self.users[email]
        else:
            print("User not found.")
            return None