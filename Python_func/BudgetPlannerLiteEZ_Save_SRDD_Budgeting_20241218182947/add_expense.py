def add_expense(self):
        try:
            amount = float(input("Enter expense amount: "))
            if amount > 0:
                self.expenses.append(amount)
                print(f"Expense of ${amount:.2f} added successfully.")
            else:
                print("Expense amount must be positive.")
        except ValueError:
            print("Invalid input. Please enter a numeric value.")