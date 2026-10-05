def remove_goal(self, goal_name):
        '''
        Removes a goal from the tracker by name.
        '''
        self.goals = [goal for goal in self.goals if goal.name != goal_name]