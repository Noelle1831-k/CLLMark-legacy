def generate_optimal_formation(self):
        # Generate optimal party formation
        self.evaluate_synergies()
        self.balance_roles()
        optimal_party = sorted(self.characters, key=lambda char: char.calculate_effectiveness(), reverse=True)
        return optimal_party