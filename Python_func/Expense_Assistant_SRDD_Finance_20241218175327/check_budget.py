def check_budget(self, category):
        total_expenses = sum(expense['amount'] for expense in self.expense_manager.get_expenses_by_category(category))
        return self.budgets.get(category, 0) >= total_expenses