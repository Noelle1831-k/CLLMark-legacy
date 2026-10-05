def find_goal(self, name):
        for goal in self.goals:
            if goal['name'] == name:
                return goal
        return None