def search_recipes(self, preferences):
        matching_recipes = []
        for recipe in self.recipes:
            if all(pref in recipe.get_ingredients() for pref in preferences):
                matching_recipes.append(recipe)
        return matching_recipes