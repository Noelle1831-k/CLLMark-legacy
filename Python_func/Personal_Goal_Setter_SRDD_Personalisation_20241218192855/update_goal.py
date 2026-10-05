def update_goal(self, goal_id, new_goal):
        '''
        Updates an existing goal with new information.
        '''
        for goal in self.goals:
            if goal['id'] == goal_id:
                goal.update(new_goal)