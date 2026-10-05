def add_user(self, user):
        '''
        Adds a user to the tracker.
        Parameters:
        - user: An instance of the User class to be added.
        '''
        if isinstance(user, User):
            self.users.append(user)
        else:
            raise TypeError("Only User instances can be added.")