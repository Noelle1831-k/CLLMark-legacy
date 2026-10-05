def set_savings_goal(self):
        try:
            self.savings_goal = float(input("Enter savings goal: "))
            if self.savings_goal < 0:
                print("Savings goal cannot be negative.")
                self.savings_goal = 0
        except ValueError:
            print("Invalid input. Please enter a numeric value.")