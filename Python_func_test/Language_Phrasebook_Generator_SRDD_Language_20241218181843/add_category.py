def add_category(self, category):
        if category not in self.categories:
            self.categories[category] = []