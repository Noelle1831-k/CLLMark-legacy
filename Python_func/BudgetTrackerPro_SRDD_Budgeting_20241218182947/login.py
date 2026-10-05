def login(self, username, password):
        if username in self.users and self.users[username].authenticate(password):
            self.current_user = self.users[username]
            print("Login successful.")
        else:
            print("Invalid username or password.")