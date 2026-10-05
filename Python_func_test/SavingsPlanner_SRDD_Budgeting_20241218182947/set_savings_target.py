def set_savings_target(self):
        """
        Prompts user to set a savings target.
        """
        try:
            target = float(input("Enter your savings target: "))
            self.budget_manager.set_savings_target(target)
        except ValueError:
            print("Invalid input. Please enter a valid number for the target.")