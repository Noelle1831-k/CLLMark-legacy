def add_income(self, income):
        try:
            self.income += float(income)
        except ValueError:
            raise ValueError("Invalid income amount. Please enter a numeric value.")