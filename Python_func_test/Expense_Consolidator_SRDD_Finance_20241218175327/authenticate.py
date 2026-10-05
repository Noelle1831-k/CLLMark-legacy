def authenticate(self):
        # User authentication with validation
        self.username = input('Enter username: ')
        self.password = input('Enter password: ')
        hashed_password = hashlib.sha256(self.password.encode()).hexdigest()
        print(f'Authenticating {self.username}...')
        if self.username in self.user_db and self.user_db[self.username] == hashed_password:
            print('Authentication successful.')
            return True
        else:
            print('Authentication failed. Invalid username or password.')
            return False