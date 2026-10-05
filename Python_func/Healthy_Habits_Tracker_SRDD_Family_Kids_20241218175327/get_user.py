def get_user(self, name):
        '''
        Retrieves a user by name.
        Parameters:
        - name: The name of the user to retrieve.
        Returns:
        - User instance if found, otherwise None.
        '''
        for user in self.users:
            if user.name == name:
                return user
        return None