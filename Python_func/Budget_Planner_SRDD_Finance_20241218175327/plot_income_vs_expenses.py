def plot_income_vs_expenses(self, income, expense):
        labels = list(income.incomes.keys()) + list(expense.expenses.keys())
        values = list(income.incomes.values()) + list(expense.expenses.values())
        plt.bar(labels, values)
        plt.title("Income vs Expenses")
        plt.xlabel("Category")
        plt.ylabel("Amount")
        plt.show()