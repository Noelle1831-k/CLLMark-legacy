def generate_report(self):
        total_income = sum(entry.amount for entry in self.income_entries)
        total_expense = sum(entry.amount for entry in self.expense_entries)
        print(f"Total Income: {total_income}")
        print(f"Total Expense: {total_expense}")
        print("\nDetailed Expenses:")
        for entry in self.expense_entries:
            print(f"Expense - {entry.category}: {entry.amount} on {entry.date}")