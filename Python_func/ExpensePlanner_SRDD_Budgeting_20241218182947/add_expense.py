def add_expense(self, category, amount):
        expense_obj = expense.Expense(category, amount)
        self.expenses.append(expense_obj)
        self.budget.update_budget(amount)
        if self.budget.check_limit():
            self.notify_exceed_limit()