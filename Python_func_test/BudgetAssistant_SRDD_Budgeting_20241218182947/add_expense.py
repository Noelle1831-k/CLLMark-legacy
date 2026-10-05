def add_expense(self):
        try:
            category = input("Enter expense category: ")
            amount = float(input("Enter expense amount: "))
            if amount < 0:
                raise ValueError("Expense amount cannot be negative.")
            if category in self.expenses:
                self.expenses[category] += amount
            else:
                self.expenses[category] = amount
            print(f"Expense added: {category} - {amount}", flush=True)
        except ValueError as e:
            print(f"Invalid input: {e}", flush=True)