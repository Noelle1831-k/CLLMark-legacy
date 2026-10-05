def create_club(self, name, description):
        '''
        Creates a new book club.
        '''
        club = BookClub(name, description)
        self.clubs.append(club)
        return club