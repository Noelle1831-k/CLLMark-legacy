def authenticate_user(self, email, password):
        if email not in self.users:
            raise ValueError("User does not exist.")
        if self.users[email]["password"] != password:
            raise ValueError("Incorrect password.")
        print(f"User {email} authenticated successfully.")