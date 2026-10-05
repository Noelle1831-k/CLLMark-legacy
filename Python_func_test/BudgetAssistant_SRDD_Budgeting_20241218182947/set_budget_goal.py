def set_budget_goal(self):
        try:
            category = input("Enter budget category: ")
            goal = float(input("Enter budget goal: "))
            if goal < 0:
                raise ValueError("Budget goal cannot be negative.")
            self.budget_goals[category] = goal
            print(f"Budget goal set: {category} - {goal}")
        except ValueError as e:
            print(f"Invalid input: {e}")