def suggest(self, ingredient):
        return self.substitutions.get(ingredient, "No substitution available")