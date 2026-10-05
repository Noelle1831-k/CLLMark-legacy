def financial_report(self):
        '''
        Generate a financial report for the hotel.
        '''
        profit = self.revenue - self.expenses
        print(f"Total Revenue: ${self.revenue}")
        print(f"Total Expenses: ${self.expenses}")
        print(f"Profit: ${profit}")