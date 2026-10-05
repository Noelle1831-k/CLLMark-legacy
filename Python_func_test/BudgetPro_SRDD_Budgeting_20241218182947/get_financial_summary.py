def get_financial_summary(self):
        '''
        Retrieve a summary of the user's financial data.
        '''
        total_expenses = sum(self.expenses)
        remaining_budget = self.budget_goal - total_expenses
        return {
            "Income": self.income,
            "Total Expenses": total_expenses,
            "Remaining Budget": remaining_budget
        }