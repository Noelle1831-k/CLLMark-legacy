def add_member(self, user):
        '''
        Adds a user to the club's member list.
        '''
        if user not in self.members:
            self.members.append(user)