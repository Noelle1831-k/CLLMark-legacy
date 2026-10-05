def get_average_rating(self, title):
        if title not in self.recipes:
            raise ValueError("Recipe does not exist.")
        ratings = self.recipes[title]["ratings"]
        return sum(ratings) / len(ratings) if ratings else None