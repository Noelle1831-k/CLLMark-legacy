def update_recipe(self, email, title, updates):
        if title not in self.recipes:
            raise ValueError("Recipe does not exist.")
        if self.recipes[title]["author"] != email:
            raise PermissionError("You are not the author of this recipe.")
        self.recipes[title].update(updates)
        print(f"Recipe '{title}' updated by {email}.")