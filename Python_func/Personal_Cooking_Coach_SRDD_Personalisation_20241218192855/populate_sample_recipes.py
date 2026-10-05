def populate_sample_recipes(self):
        # Sample recipes added to the database for demonstration
        recipes = [
            Recipe("Vegan Salad", ["lettuce", "tomato", "cucumber"], "Mix all ingredients.", {"calories": 150}),
            Recipe("Gluten-Free Pancakes", ["gluten-free flour", "milk", "egg"], "Cook on a skillet.", {"calories": 300}),
            Recipe("Vegetarian Stir Fry", ["broccoli", "carrot", "tofu"], "Stir fry all ingredients.", {"calories": 250})
        ]
        for recipe in recipes:
            self.recipe_database.add_recipe(recipe)