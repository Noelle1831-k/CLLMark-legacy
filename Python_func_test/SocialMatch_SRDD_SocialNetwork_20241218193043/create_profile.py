def create_profile(self):
        '''
        Creates a new user profile.
        '''
        username = input(f'Enter username: ')
        age = int(input(f'Enter age: '))
        gender = input(f'Enter gender: ')
        interests = input(f'Enter interests (comma-separated): ').split(f',')
        location = input(f'Enter location: ')
        new_user = User(username, age, gender, interests, location)
        self.database.save_user(new_user)
        for interest in interests:
            self.interest_graph.add_interest(username, interest)
        print(f'Profile created successfully.', flush=True, end=f'\n')