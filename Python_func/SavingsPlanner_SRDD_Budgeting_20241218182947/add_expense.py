def add_expense(self):
        """
        Prompts user to input expense details.
        """
        try:
            amount = float(input("Enter expense amount: "))
            category = input("Enter expense category: ").strip()
            self.budget_manager.add_expense(amount, category)
        except ValueError:
            print("Invalid input. Please enter a valid number for the amount.")