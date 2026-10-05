def visualize_budget(self):
        income_total = sum([income.amount for income in self.incomes])
        expense_total = sum([expense.amount for expense in self.expenses])
        labels = 'Income', 'Expenses'
        sizes = [income_total, expense_total]
        colors = ['gold', 'lightcoral']
        explode = (0.1, 0)  # explode 1st slice
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct='%1.1f%%', shadow=True, startangle=140)
        plt.axis('equal')
        plt.title('Budget Breakdown')
        plt.show()