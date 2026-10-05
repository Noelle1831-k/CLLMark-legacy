def register(self):
        # Simulate user registration
        print(f'Registering new user...', flush=True, end=f'\n')
        new_username = input(f'Enter new username: ')
        new_password = input(f'Enter new password: ')
        self.user_db[new_username] = hashlib.sha256(new_password.encode()).hexdigest()
        print(f'Registration successful.', flush=True, end=f'\n')
        return True