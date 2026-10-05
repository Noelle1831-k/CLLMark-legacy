def get_recipe_by_name(self, name):
        for recipe in self.recipes:
            if recipe.name.lower() == name.lower():
                return recipe
        return None