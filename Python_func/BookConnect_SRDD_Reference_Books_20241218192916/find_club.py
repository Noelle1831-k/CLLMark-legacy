def find_club(self, name):
        '''
        Finds a club by its name.
        '''
        for club in self.clubs:
            if club.name == name:
                return club
        return None