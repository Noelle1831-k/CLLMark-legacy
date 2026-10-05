def set_goal(self, target_amount, deadline):
        goal = Goal(target_amount, deadline)
        self.goals.append(goal)