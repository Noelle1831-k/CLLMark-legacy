def add_recipe(self, email, title, ingredients, cuisine, instructions):
        if title in self.recipes:
            raise ValueError("Recipe already exists.")
        self.recipes[title] = {
            "author": email,
            "ingredients": ingredients,
            "cuisine": cuisine,
            "instructions": instructions,
            "ratings": []
        }
        print(f"Recipe '{title}' added by {email}.")