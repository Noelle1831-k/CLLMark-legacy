def store_password(self, password):
        hashed_password = self._hash_password(password)
        self.passwords[password] = hashed_password
        print(f"Password stored: {hashed_password}")