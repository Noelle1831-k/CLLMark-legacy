def generate_bar_chart(self):
        categories = list(self.expenses.keys())
        expenses = list(self.expenses.values())
        budgets = [self.budget.get_budget_for_category(category) for category in categories]
        x = range(len(categories))
        plt.bar(x, expenses, width=0.4, label='Expenses', align='center')
        plt.bar(x, budgets, width=0.4, label='Budget', align='edge')
        plt.xlabel('Category')
        plt.ylabel('Amount')
        plt.title('Expenses vs Budget')
        plt.legend()
        plt.xticks(x, categories)
        plt.show()