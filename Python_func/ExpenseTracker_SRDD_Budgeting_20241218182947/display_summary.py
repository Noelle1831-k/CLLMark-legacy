def display_summary(self, expenses):
        total = sum(exp['amount'] for exp in expenses)
        print("\nSummary")
        print("-" * 20)
        print(f"Total Expenses: {utilities.format_currency(total)}")