def add_member(self, user):
        if user.industry == self.industry and user not in self.members:
            self.members.append(user)