def add_income(self):
        """
        Prompts user to input income details.
        """
        try:
            amount = float(input("Enter income amount: "))
            source = input("Enter income source: ").strip()
            self.budget_manager.add_income(amount, source)
        except ValueError:
            print("Invalid input. Please enter a valid number for the amount.")