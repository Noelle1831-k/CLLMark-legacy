def add_income(self):
        try:
            amount = float(input("Enter income amount: "))
            if amount > 0:
                self.income.append(amount)
                print(f"Income of ${amount:.2f} added successfully.")
            else:
                print("Income amount must be positive.")
        except ValueError:
            print("Invalid input. Please enter a numeric value.")