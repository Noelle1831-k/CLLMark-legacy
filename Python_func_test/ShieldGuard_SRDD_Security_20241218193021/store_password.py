def store_password(self, account, password):
        hashed_password = hashlib.sha256(password.encode()).hexdigest()
        self.passwords[account] = hashed_password
        print(f"Password for {account} stored securely.")