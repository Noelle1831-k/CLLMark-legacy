def remove_expense(self, expense_id):
        self.expenses = [exp for exp in self.expenses if exp['id'] != expense_id]