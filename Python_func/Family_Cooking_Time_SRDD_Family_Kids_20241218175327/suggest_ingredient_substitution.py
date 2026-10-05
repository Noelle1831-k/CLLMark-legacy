def suggest_ingredient_substitution(self, ingredient):
        suggestion = self.substitutions.suggest_substitution(ingredient)
        return suggestion