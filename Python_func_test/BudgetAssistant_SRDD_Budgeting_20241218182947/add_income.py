def add_income(self):
        try:
            income = float(input("Enter your income: "))
            if income < 0:
                raise ValueError("Income cannot be negative.")
            self.income += income
            print(f"Income updated: {self.income}")
        except ValueError as e:
            print(f"Invalid input: {e}")