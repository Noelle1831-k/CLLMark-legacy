def display_profile(self):
        '''
        Displays the current financial profile of the user.
        '''
        print(f'Income: {self.income}, Expenses: {self.expenses}, Savings Goal: {self.savings_goal}', flush=True, end='\n')