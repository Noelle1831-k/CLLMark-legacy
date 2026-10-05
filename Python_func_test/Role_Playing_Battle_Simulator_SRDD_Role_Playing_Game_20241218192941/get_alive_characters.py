def get_alive_characters(self):
        return [character for character in self.characters if character.health > 0]