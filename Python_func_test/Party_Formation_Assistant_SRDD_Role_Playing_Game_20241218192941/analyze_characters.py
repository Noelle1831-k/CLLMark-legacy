def analyze_characters(self, characters):
        for character in characters:
            effectiveness = calculate_effectiveness(character)
            self.character_analysis[character.name] = effectiveness