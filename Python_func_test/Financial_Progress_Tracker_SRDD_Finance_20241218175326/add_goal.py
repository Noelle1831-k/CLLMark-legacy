def add_goal(self):
        name = input("Enter the name of the goal: ")
        target_amount = float(input("Enter the target amount: "))
        self.app.add_goal(name, target_amount)
        print(f"Goal '{name}' with target amount {target_amount} added successfully.")