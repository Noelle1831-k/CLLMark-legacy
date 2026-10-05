def create_profile(self):
        username = input("Enter username: ")
        if username in self.users:
            print("Username already exists.")
        else:
            self.users[username] = {'progress': 0, 'goals': []}
            print(f"Profile created for {username}.")