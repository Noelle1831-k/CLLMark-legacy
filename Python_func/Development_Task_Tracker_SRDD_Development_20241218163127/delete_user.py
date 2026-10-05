def delete_user(self, user_id):
        '''
        Deletes a user from the user dictionary.
        Parameters:
        - user_id (str): The unique ID of the user to be deleted.
        '''
        if user_id in self.users:
            del self.users[user_id]