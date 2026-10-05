def calculate_progress(self, goal_name):
        '''
        Calculates and returns the progress percentage for a given goal.
        '''
        goal = self.goal_manager.get_goal(goal_name)
        if goal:
            return (goal['current'] / goal['target']) * 100
        else:
            print(f'Goal "{goal_name}" not found.', end='\n')
            return 0