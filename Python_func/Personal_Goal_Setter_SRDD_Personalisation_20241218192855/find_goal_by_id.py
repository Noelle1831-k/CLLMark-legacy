def find_goal_by_id(self, goal_id):
        '''
        Finds and returns a goal by its ID.
        '''
        for goal in self.goals:
            if goal['id'] == goal_id:
                return goal
        return None