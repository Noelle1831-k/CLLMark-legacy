def search_by_cuisine(self, cuisine):
        results = [title for title, details in self.recipes.items() if details["cuisine"].lower() == cuisine.lower()]
        print(f"Recipes found for cuisine '{cuisine}': {results}")
        return results