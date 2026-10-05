def add_income(self, source, amount):
        income = Income(source, amount)
        self.incomes.append(income)