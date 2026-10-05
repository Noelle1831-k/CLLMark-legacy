def plot_budget_breakdown(self, summary):
        '''
        Plot a pie chart of the budget breakdown.
        '''
        labels = 'Income', 'Expenses', 'Remaining Budget'
        sizes = [summary['Income'], summary['Total Expenses'], summary['Remaining Budget']]
        colors = ['gold', 'lightcoral', 'lightskyblue']
        explode = (0.1, 0, 0)  # explode 1st slice
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct='%1.1f%%', shadow=True, startangle=140)
        plt.axis('equal')
        plt.show()