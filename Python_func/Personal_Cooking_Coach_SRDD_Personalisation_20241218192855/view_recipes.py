def view_recipes(self):
        print("Viewing recipes...")
        preferences = self.user_preferences.get_preferences()
        matching_recipes = self.recipe_database.search_recipes(preferences)
        if not matching_recipes:
            print("No recipes found matching your preferences.")
        else:
            for recipe in matching_recipes:
                print(f"Recipe: {recipe.name}")
                print(f"Ingredients: {', '.join(recipe.get_ingredients())}")
                print(f"Instructions: {recipe.get_instructions()}")
                print(f"Nutritional Info: {recipe.get_nutritional_info()}\n")