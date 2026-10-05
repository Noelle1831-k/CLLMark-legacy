def get_expense_by_category(self, category):
        return [exp for exp in self.expenses if exp['category'] == category]