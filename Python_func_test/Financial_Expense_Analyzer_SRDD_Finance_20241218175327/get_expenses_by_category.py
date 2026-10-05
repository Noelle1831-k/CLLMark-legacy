def get_expenses_by_category(self, category):
        return [expense for expense in self.expenses if expense.category == category]