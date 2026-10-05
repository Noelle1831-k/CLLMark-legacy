def get_feedback(self, recipe_title):
        if recipe_title not in self.feedback:
            return []
        return self.feedback[recipe_title]