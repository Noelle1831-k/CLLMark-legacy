def show_budget_summary(self):
        '''
        Displays a summary of the user's budget including income, expenses, and balance.
        '''
        print("\nBudget Summary:")
        print(self.budget_optimizer.generate_report())