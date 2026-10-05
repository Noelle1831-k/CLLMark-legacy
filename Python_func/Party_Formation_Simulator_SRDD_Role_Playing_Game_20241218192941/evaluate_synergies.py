def evaluate_synergies(self):
        # Evaluate synergies between characters
        for char in self.characters:
            for other_char in self.characters:
                if char != other_char:
                    synergy_score = self.calculate_synergy(char, other_char)
                    self.synergies[(char.name, other_char.name)] = synergy_score