def get_expense_breakdown(self):
        '''
        Provides a breakdown of expenses by category.
        :return: A dictionary containing categories as keys and their total amounts as values.
        '''
        breakdown = {}
        for expense in self.expenses:
            category = expense['category']
            amount = expense['amount']
            breakdown[category] = breakdown.get(category, 0) + amount
        return breakdown