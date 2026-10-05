def unequip(self, character):
        for stat, value in self.stats.items():
            if stat in character.attributes:
                character.attributes[stat] -= value