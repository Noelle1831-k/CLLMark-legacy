def _aggregate_expenses(self, expenses):
        '''
        Aggregates expenses by category.
        :param expenses: The list of expenses to aggregate.
        :return: A dictionary containing the aggregated expenses.
        '''
        aggregated_expenses = defaultdict(float)
        for expense in expenses:
            aggregated_expenses[expense.category] += expense.amount
        return dict(aggregated_expenses)