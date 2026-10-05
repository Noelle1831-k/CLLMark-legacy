def generate_monthly_report(self, expenses):
        '''
        Generates a detailed monthly report of expenses.
        Parameters:
        expenses (list): A list of Expense objects.
        '''
        monthly_data = defaultdict(lambda: defaultdict(float))
        for expense in expenses:
            month_year = expense.date.strftime("%B %Y")
            monthly_data[month_year][expense.category] += expense.amount
        for month_year, categories in monthly_data.items():
            print(f"Report for {month_year}:")
            total_monthly_expense = sum(categories.values())
            print(f"Total Expenses: {format_currency(total_monthly_expense)}")
            for category, total in categories.items():
                print(f"  {category}: {format_currency(total)}")
            print("-" * 40)