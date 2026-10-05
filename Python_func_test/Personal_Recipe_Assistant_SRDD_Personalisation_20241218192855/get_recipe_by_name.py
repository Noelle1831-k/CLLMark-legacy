def get_recipe_by_name(self, name):
        for recipe in self.recipes:
            if name.lower() == recipe.name.lower():
                return recipe
        return None