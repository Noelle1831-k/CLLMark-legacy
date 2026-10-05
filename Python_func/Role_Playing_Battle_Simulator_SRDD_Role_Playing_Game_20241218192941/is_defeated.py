def is_defeated(self):
        return all(character.health <= 0 for character in self.characters)