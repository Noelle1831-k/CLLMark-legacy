def compare_with_budget(self, budget):
        '''
        Compare the total expenses with the user's budget and report the difference.
        '''
        total_expenses = sum(expense.get_amount() for expense in self.expenses)
        if total_expenses > budget:
            print(f"Over budget by {total_expenses - budget}")
        else:
            print(f"Under budget by {budget - total_expenses}")