def logout_user(self, username):
        if username in self.users:
            print(f"User {username} logged out successfully.")
            return True
        return False