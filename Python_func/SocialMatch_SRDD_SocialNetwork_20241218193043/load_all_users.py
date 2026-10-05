def load_all_users(self):
        '''
        Loads all users from the database.
        '''
        return list(self.users.values())