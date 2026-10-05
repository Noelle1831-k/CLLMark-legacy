def get_user_data(self, user_id):
        '''
        Retrieve user data.
        '''
        return self.data.get(user_id, {'income': [], 'expenses': []})