def remove_partner(self, user):
        if user in self.partners:
            self.partners.remove(user)