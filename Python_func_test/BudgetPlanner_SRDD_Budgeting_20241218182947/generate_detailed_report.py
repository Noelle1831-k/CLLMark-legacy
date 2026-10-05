def generate_detailed_report(self):
        '''
        Generate a detailed report of all incomes and expenses.
        '''
        income_details = "\n".join(f"{income.source}: {income.amount}" for income in self.incomes)
        expense_details = "\n".join(f"{expense.category} ({expense.expense_type}): {expense.amount}" for expense in self.expenses)
        return f"Incomes:\n{income_details}\n\nExpenses:\n{expense_details}"