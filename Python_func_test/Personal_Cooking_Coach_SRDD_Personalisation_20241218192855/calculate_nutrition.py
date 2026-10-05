def calculate_nutrition(self, recipes):
        self.total_nutrition = {}
        for recipe in recipes:
            for nutrient, value in recipe.get_nutritional_info().items():
                if nutrient in self.total_nutrition:
                    self.total_nutrition[nutrient] += value
                else:
                    self.total_nutrition[nutrient] = value
        if not self.total_nutrition:
            print("No nutritional data calculated.", flush=True)