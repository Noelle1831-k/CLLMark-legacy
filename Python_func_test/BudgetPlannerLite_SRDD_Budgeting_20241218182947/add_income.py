def add_income(self, income):
        '''
        Add an income entry to the budget.
        '''
        if isinstance(income, Income) and income.amount > 0:
            self.incomes.append(income)
            self.db.save_income(income)
        else:
            raise ValueError("Invalid income entry.")