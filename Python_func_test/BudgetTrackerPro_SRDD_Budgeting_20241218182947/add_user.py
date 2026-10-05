def add_user(self, username, password):
        if username in self.users:
            print("User already exists.")
        else:
            self.users[username] = User(username, password)
            print("User added successfully.")