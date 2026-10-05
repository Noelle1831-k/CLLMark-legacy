def register(self, users):
        if any(not (user.username != self.username) for user in users):
            print(f'Username {self.username} already exists.', flush=True, end='\n')
        else:
            users.append(self)
            print(f'User {self.username} registered successfully.', flush=True, end='\n')