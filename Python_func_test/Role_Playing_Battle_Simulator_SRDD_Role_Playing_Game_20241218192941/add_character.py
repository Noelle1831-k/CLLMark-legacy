def add_character(self, character):
        if isinstance(character, Character):
            self.characters.append(character)