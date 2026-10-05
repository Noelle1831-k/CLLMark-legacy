def bar_chart(self):
        categories = list(set(expense.category for expense in self.expenses))
        amounts = [sum(expense.amount for expense in self.expenses if expense.category == category) for category in categories]
        plt.bar(categories, amounts)
        plt.xlabel('Categories')
        plt.ylabel('Amount')
        plt.title('Expenses by Category')
        plt.show()