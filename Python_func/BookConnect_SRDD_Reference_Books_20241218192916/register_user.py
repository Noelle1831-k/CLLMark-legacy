def register_user(self, username, email, password):
        '''
        Registers a new user in the application.
        '''
        user = User(username, email, password)
        self.users.append(user)
        return user