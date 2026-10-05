def search_recipe(self, dietary_preferences):
        if self.dietary_info == dietary_preferences:
            return self
        else:
            return None