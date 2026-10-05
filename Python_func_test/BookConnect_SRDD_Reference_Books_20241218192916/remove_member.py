def remove_member(self, user):
        '''
        Removes a user from the club's member list.
        '''
        if user in self.members:
            self.members.remove(user)