def search_by_keyword(self, keyword):
        results = [title for title in self.recipes.keys() if keyword.lower() in title.lower()]
        print(f"Recipes found with keyword '{keyword}': {results}")
        return results