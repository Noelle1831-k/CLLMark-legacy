def calculate_profit(self):
        '''
        Calculates and returns the current profit based on revenue and expenses.
        '''
        profit = self.revenue - self.expenses
        print(f"Profit: {profit}")
        return profit