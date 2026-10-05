def apply_race_bonus(self, character):
        for attr, bonus in self.bonuses.items():
            if attr in character.attributes:
                character.attributes[attr] += bonus