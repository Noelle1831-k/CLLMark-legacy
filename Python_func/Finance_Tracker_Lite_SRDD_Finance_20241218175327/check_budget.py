def check_budget(self):
        if self.budget:
            self.budget.check_budget_status(self.expense_entries)