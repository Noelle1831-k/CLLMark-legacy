def get_budget_balance(self):
        '''
        Calculate the budget balance.
        '''
        return self.get_total_income() - self.get_total_expenses()