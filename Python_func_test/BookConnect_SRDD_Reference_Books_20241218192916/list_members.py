def list_members(self):
        '''
        Lists all members of the book club.
        '''
        return [member.username for member in self.members]