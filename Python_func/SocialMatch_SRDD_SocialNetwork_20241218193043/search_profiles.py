def search_profiles(self, interest):
        '''
        Searches for profiles based on a specific interest.
        '''
        users = self.database.load_all_users()
        return [user for user in users if interest in user.interests]