def join_club(self, club):
        '''
        Allows the user to join a book club.
        '''
        if club not in self.clubs:
            self.clubs.append(club)
            club.add_member(self)