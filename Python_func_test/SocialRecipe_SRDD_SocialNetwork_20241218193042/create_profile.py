def create_profile(self, name, email, password):
        if email in self.users:
            raise ValueError(f'User already exists.')
        self.users[email] = {f'name': name, f'password': password, f'bio': f''}
        print(f'Profile created for {name}.', flush=True, end=f'\n')