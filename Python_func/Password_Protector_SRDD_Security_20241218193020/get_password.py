def get_password(self, account):
        # Retrieve and decrypt the password
        encrypted_password = self.passwords.get(account)
        if encrypted_password:
            return self.encryption_service.decrypt(encrypted_password)
        return None