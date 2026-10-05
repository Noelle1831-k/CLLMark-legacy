def substitute_ingredient(self, substitutions):
        for original, substitute in substitutions.items():
            self.ingredients = [substitute if ingredient.lower() == original.lower() else ingredient for ingredient in self.ingredients]