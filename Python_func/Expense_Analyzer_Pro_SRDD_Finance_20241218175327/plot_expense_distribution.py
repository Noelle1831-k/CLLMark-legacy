def plot_expense_distribution(self, expenses_by_category):
        categories = list(expenses_by_category.keys())
        amounts = [sum(expenses) for expenses in expenses_by_category.values()]
        plt.figure(figsize=(10, 6))
        plt.bar(categories, amounts, color='skyblue')
        plt.xlabel('Category')
        plt.ylabel('Total Expenses')
        plt.title('Expense Distribution by Category')
        plt.show()