def generate_meal_plan(self, preferences):
        self.meal_plan = self.recipe_database.search_recipes(preferences)
        if not self.meal_plan:
            print("No suitable recipes found for meal plan.")