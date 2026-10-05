def plot_budget_breakdown(self, income, expenses):
        '''
        Plots a pie chart showing the breakdown of income and expenses.
        Arguments:
        income -- The list of income records.
        expenses -- The list of expense records.
        '''
        labels = ['Income', 'Expenses']
        sizes = [sum(item['amount'] for item in income), sum(item['amount'] for item in expenses)]
        colors = ['#ff9999', '#66b3ff']
        explode = (0.1, 0)  # explode 1st slice
        plt.pie(sizes, explode=explode, labels=labels, colors=colors, autopct='%1.1f%%', shadow=True, startangle=140)
        plt.axis('equal')
        plt.title('Budget Breakdown')
        plt.show()