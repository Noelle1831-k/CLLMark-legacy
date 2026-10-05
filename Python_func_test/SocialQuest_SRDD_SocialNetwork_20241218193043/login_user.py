def login_user(self, username, password):
        if username in self.users and self.users[username]['password'] == password:
            print(f'User {username} logged in successfully.', end='\n')
            return True
        print('Login failed.', end='\n')
        return False