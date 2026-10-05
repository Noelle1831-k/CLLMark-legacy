def filter_recipes(self, dietary_restrictions):
        filtered_recipes = []
        for recipe in self.recipes:
            if not any(restriction in [ingredient.lower() for ingredient in recipe.ingredients] for restriction in dietary_restrictions):
                filtered_recipes.append(recipe)
        return filtered_recipes