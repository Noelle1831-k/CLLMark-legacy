def remove_goal(self, goal_id):
        '''
        Removes a goal from the list based on its ID.
        '''
        self.goals = [goal for goal in self.goals if goal['id'] != goal_id]