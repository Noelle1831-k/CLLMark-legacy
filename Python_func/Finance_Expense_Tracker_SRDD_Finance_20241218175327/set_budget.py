def set_budget(self, category, amount):
        '''
        Sets a budget for a specific category.
        :param category: Category for the budget.
        :param amount: Budget amount.
        '''
        self.budgets[category] = Budget(category, amount)