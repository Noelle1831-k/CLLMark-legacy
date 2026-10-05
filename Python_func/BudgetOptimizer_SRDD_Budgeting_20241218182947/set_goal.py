def set_goal(self, amount):
        if amount < 0:
            print("Budget goal cannot be negative.")
        else:
            self.goal_amount = amount