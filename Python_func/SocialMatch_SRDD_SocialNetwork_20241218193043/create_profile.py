def create_profile(self):
        '''
        Creates a new user profile.
        '''
        username = input("Enter username: ")
        age = int(input("Enter age: "))
        gender = input("Enter gender: ")
        interests = input("Enter interests (comma-separated): ").split(',')
        location = input("Enter location: ")
        new_user = User(username, age, gender, interests, location)
        self.database.save_user(new_user)
        for interest in interests:
            self.interest_graph.add_interest(username, interest)
        print("Profile created successfully.")