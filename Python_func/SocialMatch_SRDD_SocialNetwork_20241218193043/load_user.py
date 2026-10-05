def load_user(self, username):
        '''
        Loads a user from the database.
        '''
        return self.users.get(username)