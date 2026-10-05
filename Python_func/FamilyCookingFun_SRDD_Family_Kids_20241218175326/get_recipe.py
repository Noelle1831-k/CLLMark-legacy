def get_recipe(self, name):
        for recipe in self.recipes:
            if recipe.name == name:
                return recipe
        logging.warning(f"Recipe not found: {name}")
        return None