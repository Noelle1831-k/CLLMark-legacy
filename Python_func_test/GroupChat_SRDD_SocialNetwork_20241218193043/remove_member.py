def remove_member(self, user):
        if user in self.members:
            self.members.remove(user)