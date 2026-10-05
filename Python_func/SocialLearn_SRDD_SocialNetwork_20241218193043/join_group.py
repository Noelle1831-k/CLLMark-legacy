def join_group(self, user):
        if user not in self.members:
            self.members.append(user)