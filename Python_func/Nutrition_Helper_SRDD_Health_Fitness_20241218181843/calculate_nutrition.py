def calculate_nutrition(self):
        total_nutrition = {"calories": 0, "macronutrients": {}, "micronutrients": {}}
        for item in self.items:
            nutrition = item.get_nutrition()
            total_nutrition["calories"] += nutrition["calories"]
            for macro, amount in nutrition["macronutrients"].items():
                if macro in total_nutrition["macronutrients"]:
                    total_nutrition["macronutrients"][macro] += amount
                else:
                    total_nutrition["macronutrients"][macro] = amount
            for micro, amount in nutrition["micronutrients"].items():
                if micro in total_nutrition["micronutrients"]:
                    total_nutrition["micronutrients"][micro] += amount
                else:
                    total_nutrition["micronutrients"][micro] = amount
        return total_nutrition