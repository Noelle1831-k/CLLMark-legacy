def login_user(self, username, password):
        user = self.database.find_user(username)
        if user and user.verify_password(password):
            return user
        else:
            raise ValueError("Invalid username or password")