def set_goal(self, goal):
        '''
        Sets a budget goal.
        If the goal is negative or zero, the goal is reset to zero.
        '''
        if goal > 0:
            self.goal = goal
        else:
            print("Invalid goal amount. Goal must be greater than zero.")
            self.goal = 0