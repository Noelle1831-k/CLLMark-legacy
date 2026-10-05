def generate(self):
        total_income = sum(income.amount for income in self.incomes)
        total_expense = sum(expense.amount for expense in self.expenses)
        print(f"Total Income: {total_income}")
        print(f"Total Expense: {total_expense}")
        for expense in self.expenses:
            print(f"Category: {expense.category}, Amount: {expense.amount}, Description: {expense.description}")