def get_budget_for_category(self, category):
        return self.category_budgets.get(category, 0)