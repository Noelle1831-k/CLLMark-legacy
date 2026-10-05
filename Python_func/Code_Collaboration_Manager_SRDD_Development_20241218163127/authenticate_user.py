def authenticate_user(self):
        # Secure user authentication
        username = input("Enter username: ")
        password = getpass.getpass("Enter password: ")
        if self.verify_credentials(username, password):
            self.current_user = username
            print(f"Welcome, {username}!")
        else:
            print("Authentication failed.")