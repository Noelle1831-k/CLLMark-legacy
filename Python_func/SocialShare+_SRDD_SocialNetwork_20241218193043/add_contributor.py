def add_contributor(self, user):
        if user not in self.contributors:
            self.contributors.append(user)