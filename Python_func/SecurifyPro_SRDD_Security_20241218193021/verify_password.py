def verify_password(self, password):
        print("Verifying password...")
        # Simulate password verification
        encrypted_password = hashlib.sha256(password.encode()).hexdigest()
        print(f"Password verification successful for: {encrypted_password}")