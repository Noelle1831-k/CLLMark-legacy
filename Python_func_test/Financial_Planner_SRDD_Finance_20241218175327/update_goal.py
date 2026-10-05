def update_goal(self, goal_name, amount):
        if goal_name in self.goals:
            self.goals[goal_name]["saved"] += amount