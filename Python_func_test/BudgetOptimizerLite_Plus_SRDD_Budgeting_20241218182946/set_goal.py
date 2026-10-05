def set_goal(self, name, amount):
        goal = Goal(name, amount)
        self.goals.append(goal)