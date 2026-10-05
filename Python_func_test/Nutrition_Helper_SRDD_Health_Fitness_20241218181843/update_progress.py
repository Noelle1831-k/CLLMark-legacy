def update_progress(self, meal):
        nutrition = meal.calculate_nutrition()
        self.progress["calories"] += nutrition["calories"]
        for macro, amount in nutrition["macronutrients"].items():
            if macro in self.progress["macronutrients"]:
                self.progress["macronutrients"][macro] += amount
            else:
                self.progress["macronutrients"][macro] = amount
        for micro, amount in nutrition["micronutrients"].items():
            if micro in self.progress["micronutrients"]:
                self.progress["micronutrients"][micro] += amount
            else:
                self.progress["micronutrients"][micro] = amount
        self.meals.append(meal)