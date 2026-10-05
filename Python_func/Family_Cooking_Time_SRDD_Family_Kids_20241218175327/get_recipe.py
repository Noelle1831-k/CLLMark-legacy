def get_recipe(self, title):
        if self.title == title:
            return self
        else:
            return None