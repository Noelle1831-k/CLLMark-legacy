def plot_expenses(self, expenses):
        '''
        Plots expenses by category using a pie chart.
        :param expenses: List of expenses.
        '''
        categories = {}
        for expense in expenses:
            if expense.category not in categories:
                categories[expense.category] = 0
            categories[expense.category] += expense.amount
        labels = categories.keys()
        sizes = categories.values()
        plt.figure(figsize=(10, 5))
        plt.pie(sizes, labels=labels, autopct=f'%1.1f%%')
        plt.title(f'Expenses by Category')
        plt.show()