def set_goal(self):
        """
        Allow the user to set a personalized savings goal.
        """
        while True:
            goal = input("Enter your savings goal (e.g., 1000 for $1000): ")
            try:
                self.savings_goal = float(goal)
                if self.savings_goal <= 0:
                    print("Please enter a positive value for your savings goal.")
                    continue
                break
            except ValueError:
                print("Please enter a valid number.")
        print(f"Savings goal of ${self.savings_goal} set.")