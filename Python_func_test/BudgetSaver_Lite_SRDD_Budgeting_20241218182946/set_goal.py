def set_goal(self, goal):
        while True:
            try:
                self.goal = float(goal)
                break
            except ValueError:
                goal = input("Invalid input. Please enter a numeric value for budget goal: ")