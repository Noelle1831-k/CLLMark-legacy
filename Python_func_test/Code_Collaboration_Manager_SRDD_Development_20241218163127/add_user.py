def add_user(self, username, password):
        if username not in self.users:
            self.users[username] = self.hash_password(password)
            print(f"User {username} added.")
        else:
            print(f"User {username} already exists.")