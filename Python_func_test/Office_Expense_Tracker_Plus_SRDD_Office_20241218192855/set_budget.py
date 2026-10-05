def set_budget(self, category, limit):
        '''
        Sets a budget for a specific category.
        Parameters:
        category (str): The category for which to set the budget.
        limit (float): The budget limit.
        '''
        if category not in self.budgets:
            self.budgets[category] = Budget(category, limit)
            print(f'Budget set for {category}: {format_currency(limit)}', flush=True, end='\n')
        else:
            self.budgets[category].set_limit(limit)
            print(f'Budget updated for {category}: {format_currency(limit)}', flush=True, end='\n')