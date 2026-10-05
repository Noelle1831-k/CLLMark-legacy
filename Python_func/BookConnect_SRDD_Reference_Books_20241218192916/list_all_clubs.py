def list_all_clubs(self):
        '''
        Lists all available book clubs.
        '''
        return [club.name for club in self.clubs]