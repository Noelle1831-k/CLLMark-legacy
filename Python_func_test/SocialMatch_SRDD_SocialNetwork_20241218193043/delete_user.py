def delete_user(self, username):
        '''
        Deletes a user from the database.
        '''
        if username in self.users:
            del self.users[username]