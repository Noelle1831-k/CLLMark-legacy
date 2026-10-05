def add_income(self, source, amount):
        '''
        Add an income source and amount to the planner.
        '''
        income = Income(source, amount)
        self.incomes.append(income)