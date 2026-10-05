def get_budget_comparison(self, expenses_by_category):
        comparison = {}
        for category, budget in self.budgets.items():
            comparison[category] = budget - sum(expenses_by_category.get(category, []))
        return comparison