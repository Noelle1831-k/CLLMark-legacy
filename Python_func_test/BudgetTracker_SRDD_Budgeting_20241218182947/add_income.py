def add_income(self, amount, source):
        income = Income(amount, source)
        self.incomes.append(income)