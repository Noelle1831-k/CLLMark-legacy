def get_expenses_by_category(self, category_name):
        if category_name in self.categories:
            return self.categories[category_name].expenses
        return []