def create_bar_chart(self):
        categories = list(set(entry.category for entry in self.expense_entries))
        amounts = [sum(entry.amount for entry in self.expense_entries if entry.category == category) for category in categories]
        plt.bar(categories, amounts)
        plt.title('Expenses by Category')
        plt.xlabel('Category')
        plt.ylabel('Amount')
        plt.show()