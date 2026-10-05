def run_application():
    user_prefs = UserPreferences()
    recipe_db = RecipeDatabase()
    recipe_gen = RecipeGenerator()
    user_prefs.set_preferences()
    recipe_db.load_recipes()
    personalized_recipes = recipe_gen.generate_personalized_recipes(user_prefs, recipe_db)
    if personalized_recipes:
        print("\nPersonalized Recipe Recommendations:\n")
        for recipe in personalized_recipes:
            print(f"Recipe: {recipe.name}")
            print("Ingredients:")
            for ingredient in recipe.ingredients:
                print(f"- {ingredient}")
            print("Instructions:")
            print(recipe.instructions)
            print("\n")
    else:
        print("No recipes match your preferences. Please adjust your preferences and try again.")