def save_user(self, user):
        '''
        Saves a user to the database.
        '''
        self.users[user.username] = user