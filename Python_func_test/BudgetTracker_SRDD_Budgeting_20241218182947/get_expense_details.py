def get_expense_details(self):
        return [expense.get_details() for expense in self.expenses]