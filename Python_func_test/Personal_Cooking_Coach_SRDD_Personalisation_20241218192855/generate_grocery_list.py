def generate_grocery_list(self):
        print("Generating grocery list...")
        meal_plan = self.meal_planner.get_meal_plan()
        self.grocery_list_generator.generate_list(meal_plan)
        grocery_list = self.grocery_list_generator.get_grocery_list()
        if not grocery_list:
            print("No grocery list could be generated.")
        else:
            print("Grocery List:")
            for item in grocery_list:
                print(f"- {item}")