def add_comment(self, user, comment):
        '''
        Adds a comment to the discussion.
        '''
        self.comments.append((user.username, comment))