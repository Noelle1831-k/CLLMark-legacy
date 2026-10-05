def suggest(self, ingredient):
        return self.substitutions.get(ingredient, f"No substitution available")