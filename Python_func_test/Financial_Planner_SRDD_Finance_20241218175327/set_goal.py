def set_goal(self, goal_name, amount, deadline):
        self.goals[goal_name] = {"amount": amount, "deadline": deadline, "saved": 0}