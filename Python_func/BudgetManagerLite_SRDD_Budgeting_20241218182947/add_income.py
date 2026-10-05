def add_income(self, amount, source):
        amount = validate_amount(amount)  # Validate the amount
        income = Income(amount, source)
        self.incomes.append(income)