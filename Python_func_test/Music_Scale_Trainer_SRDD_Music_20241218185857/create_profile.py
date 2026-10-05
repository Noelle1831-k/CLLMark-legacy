def create_profile(self):
        while True:
            username = input('Enter your username: ').strip()
            if self.is_valid_username(username):
                self.profile['username'] = username
                self.progress[username] = {'completed_exercises': 0}
                print(f'Profile created for user: {username}', end='\n')
                break
            else:
                print('Invalid username. It must be non-empty and less than 20 characters.', end='\n')