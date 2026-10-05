def get_recipe_by_id(self, recipe_id):
        if 0 <= recipe_id < len(self.recipes):
            return self.recipes[recipe_id]
        return None