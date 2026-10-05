def find_family_member(self, name):
        for member in self.family_members:
            if member.name == name:
                return member
        return None