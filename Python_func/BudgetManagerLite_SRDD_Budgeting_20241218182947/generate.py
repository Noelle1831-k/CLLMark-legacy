def generate(self):
        report = "Income Report:\n"
        for income in self.incomes:
            report += f"Source: {income.source}, Amount: {income.amount}\n"
        report += "\nExpense Report:\n"
        for expense in self.expenses:
            report += f"Category: {expense.category}, Amount: {expense.amount}\n"
        total_income = sum(income.amount for income in self.incomes)
        total_expense = sum(expense.amount for expense in self.expenses)
        report += f"\nTotal Income: {total_income}\n"
        report += f"Total Expenses: {total_expense}\n"
        report += f"Net Balance: {total_income - total_expense}\n"
        return report