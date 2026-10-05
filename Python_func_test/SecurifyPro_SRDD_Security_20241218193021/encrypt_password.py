def encrypt_password(self, password):
        print("Encrypting password...")
        # Simulate password encryption
        encrypted_password = hashlib.sha256(password.encode()).hexdigest()
        print(f"Encrypted password: {encrypted_password}")