def create_charts(self):
        categories = [expense.category for expense in self.expenses]
        amounts = [expense.amount for expense in self.expenses]
        plt.pie(amounts, labels=categories, autopct=f"%1.1f%%")
        plt.title(f"Expenses by Category")
        plt.show()