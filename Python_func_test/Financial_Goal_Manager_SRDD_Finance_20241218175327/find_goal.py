def find_goal(self, name):
        for goal in self.goals:
            if name == goal[f'name']:
                return goal
        return