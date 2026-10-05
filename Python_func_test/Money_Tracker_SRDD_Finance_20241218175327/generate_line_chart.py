def generate_line_chart(self, user):
        '''
        Generates a line chart showing the trend of income and expenses over time.
        '''
        income_dates = [t.date for t in user.income]
        expense_dates = [t.date for t in user.expenses]
        income_amounts = [t.amount for t in user.income]
        expense_amounts = [t.amount for t in user.expenses]
        plt.figure(figsize=(12, 6))
        plt.plot(income_dates, income_amounts, label='Income', color='green', marker='o')
        plt.plot(expense_dates, expense_amounts, label='Expenses', color='red', marker='x')
        plt.xlabel('Date')
        plt.ylabel('Amount')
        plt.title('Income and Expenses Over Time')
        plt.legend()
        plt.grid(True)
        plt.show()