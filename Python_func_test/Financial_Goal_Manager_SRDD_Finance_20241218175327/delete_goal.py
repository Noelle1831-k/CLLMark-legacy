def delete_goal(self, name):
        self.goals = [goal for goal in self.goals if goal['name'] != name]