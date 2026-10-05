def remove_member(self, character):
        self.members.remove(character)
        self.calculate_synergy()