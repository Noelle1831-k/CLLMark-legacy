def analyze_yearly_trends(self):
        '''
        Analyzes yearly trends in expenses.
        Returns a dictionary with years as keys and total expenses as values.
        '''
        yearly_trends = defaultdict(float)
        for expense in self.expense_manager.expenses:
            year = self._get_year_from_description(expense.description)
            yearly_trends[year] += expense.amount
        return dict(yearly_trends)