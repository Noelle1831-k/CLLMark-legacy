def get_user_by_id(self, user_id):
        '''
        Retrieves a user by their unique ID.
        Parameters:
        - user_id (str): The unique ID of the user.
        Returns:
        - User: The user object if found, else None.
        '''
        return self.users.get(user_id, None)