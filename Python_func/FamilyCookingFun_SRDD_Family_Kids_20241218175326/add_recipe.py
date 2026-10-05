def add_recipe(self, name, ingredients, instructions):
        recipe = Recipe(name, ingredients, instructions)
        self.recipes.append(recipe)
        logging.info(f"Added recipe: {name}")