def delete_profile(self):
        '''
        Deletes an existing user profile.
        '''
        username = input('Enter username to delete: ')
        self.database.delete_user(username)
        self.interest_graph.remove_user(username)
        print('Profile deleted successfully.')