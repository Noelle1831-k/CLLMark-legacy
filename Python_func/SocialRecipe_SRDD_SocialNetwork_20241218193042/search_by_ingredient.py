def search_by_ingredient(self, ingredient):
        results = [title for title, details in self.recipes.items() if ingredient.lower() in map(str.lower, details["ingredients"])]
        print(f"Recipes found with ingredient '{ingredient}': {results}")
        return results