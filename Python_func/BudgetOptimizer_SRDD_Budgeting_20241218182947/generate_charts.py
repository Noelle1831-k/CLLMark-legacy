def generate_charts(self, income_tracker, expense_tracker):
        import matplotlib.pyplot as plt
        categories = expense_tracker.categorize_expenses()
        labels = categories.keys()
        sizes = categories.values()
        plt.pie(sizes, labels=labels, autopct='%1.1f%%')
        plt.axis('equal')
        plt.title("Expense Distribution")
        plt.show()