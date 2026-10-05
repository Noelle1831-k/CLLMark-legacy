def generate_report(self):
        '''
        Generate a financial report based on incomes and expenses.
        '''
        return Report(self.incomes, self.expenses)