def register(self):
        username = input(f'Enter username: ')
        password = input(f'Enter password: ')
        new_user = user.User(username, password)
        self.users.append(new_user)
        print(f'Registration successful!', flush=True, end=f'\n')