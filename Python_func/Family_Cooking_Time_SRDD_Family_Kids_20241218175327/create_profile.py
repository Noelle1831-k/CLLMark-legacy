def create_profile(self, username, dietary_preferences):
        if username in self.users:
            print(f"User {username} already exists.")
        else:
            self.users[username] = UserProfile(username, dietary_preferences)
            print(f"Profile created for {username}.")