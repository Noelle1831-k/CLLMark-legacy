def add_member(self, user):
        if user not in self.members:
            self.members.append(user)