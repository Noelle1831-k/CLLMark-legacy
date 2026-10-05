def save_favorite_recipe(self, recipe):
        self.favorite_recipes.append(recipe)
        print(f"Recipe {recipe.title} added to favorites.")