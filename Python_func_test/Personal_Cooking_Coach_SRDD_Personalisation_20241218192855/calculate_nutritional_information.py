def calculate_nutritional_information(self):
        print("Calculating nutritional information...")
        meal_plan = self.meal_planner.get_meal_plan()
        self.nutritional_calculator.calculate_nutrition(meal_plan)
        total_nutrition = self.nutritional_calculator.get_total_nutrition()
        if not total_nutrition:
            print("No nutritional information available.")
        else:
            print("Total Nutritional Information:")
            for nutrient, value in total_nutrition.items():
                print(f"{nutrient}: {value}")