def create_income_vs_expense_chart(self, incomes, expenses):
        '''
        Creates a side-by-side comparison of total income versus total expenses.
        Args:
            incomes (list): A list of Income objects.
            expenses (list): A list of Expense objects.
        '''
        total_income = sum(income.amount for income in incomes)
        total_expenses = sum(expense.amount for expense in expenses)
        categories = ['Total Income', 'Total Expenses']
        values = [total_income, total_expenses]
        # Plotting the income vs expense chart
        plt.figure(figsize=(8, 6))
        plt.bar(categories, values, color=['green', 'red'], edgecolor='black')
        plt.xlabel('Category', fontsize=12)
        plt.ylabel('Amount ($)', fontsize=12)
        plt.title('Income vs Expenses', fontsize=16)
        # Displaying value annotations on top of each bar
        for i, v in enumerate(values):
            plt.text(i, v + 100, f"${v:.2f}", ha='center', fontsize=12)
        plt.tight_layout()
        plt.show()