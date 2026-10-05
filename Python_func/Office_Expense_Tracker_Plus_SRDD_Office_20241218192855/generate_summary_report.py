def generate_summary_report(self, expenses):
        '''
        Generates a summary report of all expenses.
        Parameters:
        expenses (list): A list of Expense objects.
        '''
        summary_data = defaultdict(float)
        for expense in expenses:
            summary_data[expense.category] += expense.amount
        print("Summary Report of All Expenses:")
        total_expense = sum(summary_data.values())
        print(f"Total Expenses: {format_currency(total_expense)}")
        for category, total in summary_data.items():
            print(f"  {category}: {format_currency(total)}")
        print("=" * 40)