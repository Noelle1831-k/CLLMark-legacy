def delete_goal(self, goal_name):
        if goal_name in self.goals:
            del self.goals[goal_name]