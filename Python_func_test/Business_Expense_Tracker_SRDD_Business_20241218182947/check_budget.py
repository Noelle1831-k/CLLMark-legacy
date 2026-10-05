def check_budget(self, category, current_expense):
        '''
        Checks if the current expense is within the budget for the category.
        '''
        if category in self.budgets:
            return current_expense <= self.budgets[category]
        return True