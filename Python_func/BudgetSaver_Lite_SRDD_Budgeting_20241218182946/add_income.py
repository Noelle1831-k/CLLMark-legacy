def add_income(self, amount):
        while True:
            try:
                amount = float(amount)
                self.income.append(amount)
                break
            except ValueError:
                amount = input("Invalid input. Please enter a numeric value for income: ")