def verify_credentials(self, username, password):
        # Verify credentials with hashed password
        if username in self.users:
            stored_hash = self.users[username]
            return self.hash_password(password) == stored_hash
        return False