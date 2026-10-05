def suggest_substitution(self, ingredient):
        return self.substitutions.get(ingredient, "No substitution found")