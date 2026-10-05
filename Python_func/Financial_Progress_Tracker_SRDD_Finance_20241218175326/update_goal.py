def update_goal(self):
        name = input("Enter the name of the goal to update: ")
        amount = float(input("Enter the amount to add: "))
        self.app.update_goal(name, amount)
        print(f"Goal '{name}' updated with amount {amount}.")