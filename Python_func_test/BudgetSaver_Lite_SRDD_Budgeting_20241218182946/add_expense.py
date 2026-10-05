def add_expense(self, amount):
        while True:
            try:
                amount = float(amount)
                self.expenses.append(amount)
                break
            except ValueError:
                amount = input("Invalid input. Please enter a numeric value for expense: ")