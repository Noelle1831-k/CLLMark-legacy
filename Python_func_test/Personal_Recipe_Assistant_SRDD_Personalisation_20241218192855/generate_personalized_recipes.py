def generate_personalized_recipes(self, user_prefs, recipe_db):
        filtered_recipes = recipe_db.filter_recipes(user_prefs.dietary_restrictions)
        personalized_recipes = []
        for recipe in filtered_recipes:
            if any(flavor in [ingredient.lower() for ingredient in recipe.ingredients] for flavor in user_prefs.flavor_preferences):
                personalized_recipes.append(recipe)
        return personalized_recipes