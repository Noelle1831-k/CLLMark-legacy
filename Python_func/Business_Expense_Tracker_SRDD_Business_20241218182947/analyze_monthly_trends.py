def analyze_monthly_trends(self):
        '''
        Analyzes monthly trends in expenses.
        Returns a dictionary with months as keys and total expenses as values.
        '''
        monthly_trends = defaultdict(float)
        for expense in self.expense_manager.expenses:
            month = self._get_month_from_description(expense.description)
            monthly_trends[month] += expense.amount
        return dict(monthly_trends)