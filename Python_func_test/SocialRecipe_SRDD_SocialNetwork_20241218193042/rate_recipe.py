def rate_recipe(self, title, rating):
        if title not in self.recipes:
            raise ValueError("Recipe does not exist.")
        if rating < 1 or rating > 5:
            raise ValueError("Rating must be between 1 and 5.")
        self.recipes[title]["ratings"].append(rating)
        print(f"Recipe '{title}' rated with a score of {rating}.")