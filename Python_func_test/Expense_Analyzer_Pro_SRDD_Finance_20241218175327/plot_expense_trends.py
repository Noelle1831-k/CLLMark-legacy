def plot_expense_trends(self, expenses_by_category):
        categories = list(expenses_by_category.keys())
        amounts = [sum(expenses) for expenses in expenses_by_category.values()]
        plt.figure(figsize=(10, 6))
        plt.plot(categories, amounts, marker='o', linestyle='-', color='skyblue')
        plt.xlabel('Category')
        plt.ylabel('Total Expenses')
        plt.title('Expense Trends by Category')
        plt.show()