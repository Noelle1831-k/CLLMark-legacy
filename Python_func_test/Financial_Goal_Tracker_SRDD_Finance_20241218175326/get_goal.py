def get_goal(self, goal_name):
        '''
        Retrieves a specific goal by name.
        '''
        for goal in self.goals:
            if goal.name == goal_name:
                return goal
        return None