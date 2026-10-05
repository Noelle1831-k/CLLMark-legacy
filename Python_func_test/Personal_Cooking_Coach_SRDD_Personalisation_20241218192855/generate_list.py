def generate_list(self, recipes):
        self.grocery_list = []
        for recipe in recipes:
            for ingredient in recipe.get_ingredients():
                if ingredient not in self.grocery_list:
                    self.grocery_list.append(ingredient)
        if not self.grocery_list:
            print("No ingredients found for grocery list.")