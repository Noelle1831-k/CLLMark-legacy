def set_goal(self, goal):
        '''
        Set a budgeting goal.
        '''
        if isinstance(goal, Goal) and goal.target_amount > 0:
            self.goals.append(goal)
            self.db.save_goal(goal)
        else:
            raise ValueError("Invalid goal entry.")