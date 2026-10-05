def add_income(self, amount, description):
        income = Income(amount, description)
        self.incomes.append(income)