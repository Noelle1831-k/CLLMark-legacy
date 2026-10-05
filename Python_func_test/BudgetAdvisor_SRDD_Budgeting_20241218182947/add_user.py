def add_user(self, username, income, expenses, goals=None):
        if username not in self.users:
            self.users[username] = UserProfile(username, income, expenses, goals)
            self.data_storage.save_data(self.users)
        else:
            print(f"User {username} already exists.", flush=True, end="\n")