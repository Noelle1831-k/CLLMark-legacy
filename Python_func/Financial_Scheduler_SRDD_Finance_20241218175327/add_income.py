def add_income(self, name, amount, frequency, start_date):
        income = Transaction(name, amount, frequency, start_date)
        self.incomes.append(income)