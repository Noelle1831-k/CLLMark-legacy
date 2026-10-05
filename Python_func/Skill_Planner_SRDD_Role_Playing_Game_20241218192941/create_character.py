def create_character(self, name):
        character = Character(name)
        self.characters.append(character)
        return character