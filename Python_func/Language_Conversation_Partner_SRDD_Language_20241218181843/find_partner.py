def find_partner(self, user):
        # Add the user to the partners list
        self.add_partner(user)
        # Find a suitable partner
        for partner in self.partners:
            if partner.native_language == user.learning_language and partner.learning_language == user.native_language:
                return partner
        return None