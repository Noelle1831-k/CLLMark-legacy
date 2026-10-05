def create_bar_chart(self, incomes, expenses):
        '''
        Creates a bar chart representing the budget breakdown.
        The chart shows income sources and expense categories with their respective amounts.
        Args:
            incomes (list): A list of Income objects.
            expenses (list): A list of Expense objects.
        '''
        labels = [income.source for income in incomes] + [expense.category for expense in expenses]
        sizes = [income.amount for income in incomes] + [expense.amount for expense in expenses]
        # Plotting the bar chart
        plt.figure(figsize=(10, 6))
        plt.bar(labels, sizes, color='blue', edgecolor='black')
        plt.xlabel('Categories', fontsize=12)
        plt.ylabel('Amount', fontsize=12)
        plt.title('Budget Breakdown by Income and Expense Categories', fontsize=16)
        # Customizing the x-axis labels to prevent overlap
        plt.xticks(rotation=45, ha='right')
        plt.tight_layout()  # Adjust layout to prevent clipping of labels
        plt.show()