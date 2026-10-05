def plot_budget_breakdown(self, budget_summary):
        labels = 'Income', 'Expenses'
        sizes = [budget_summary['total_income'], budget_summary['total_expenses']]
        colors = ['green', 'red']
        explode = (0.1, 0)  # explode 1st slice
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct='%1.1f%%', shadow=True, startangle=140)
        plt.axis('equal')
        plt.title('Budget Breakdown')
        plt.show()