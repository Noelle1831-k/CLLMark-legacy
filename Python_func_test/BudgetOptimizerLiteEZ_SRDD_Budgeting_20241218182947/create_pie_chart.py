def create_pie_chart(self, incomes, expenses):
        '''
        Creates a pie chart that represents the distribution of income and expenses.
        The pie chart includes labels for each income source and expense category, 
        as well as a visual distinction for each segment.
        Args:
            incomes (list): A list of Income objects.
            expenses (list): A list of Expense objects.
        '''
        labels = [income.source for income in incomes] + [expense.category for expense in expenses]
        sizes = [income.amount for income in incomes] + [expense.amount for expense in expenses]
        colors = ['gold', 'yellowgreen', 'lightcoral', 'lightskyblue']
        explode = (0.1, 0, 0, 0)  # explode 1st slice
        # Plotting the pie chart
        plt.figure(figsize=(8, 8))
        plt.pie(sizes, explode=explode, labels=labels, colors=colors,
                autopct='%1.1f%%', shadow=True, startangle=140)
        plt.axis('equal')  # Equal aspect ratio ensures the pie chart is circular.
        plt.title('Income and Expense Breakdown', fontsize=16)
        plt.show()