def register(self):
        # Simulate user registration
        print("Registering new user...")
        new_username = input("Enter new username: ")
        new_password = input("Enter new password: ")
        self.user_db[new_username] = hashlib.sha256(new_password.encode()).hexdigest()
        print("Registration successful.")
        return True