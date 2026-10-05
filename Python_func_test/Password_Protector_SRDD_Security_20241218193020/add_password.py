def add_password(self, account, password):
        # Encrypt the password before storing
        encrypted_password = self.encryption_service.encrypt(password)
        self.passwords[account] = encrypted_password