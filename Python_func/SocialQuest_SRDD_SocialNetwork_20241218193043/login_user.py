def login_user(self, username, password):
        if username in self.users and self.users[username]['password'] == password:
            print(f"User {username} logged in successfully.")
            return True
        print("Login failed.")
        return False