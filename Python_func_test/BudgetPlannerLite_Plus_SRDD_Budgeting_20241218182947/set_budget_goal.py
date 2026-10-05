def set_budget_goal(self, goal):
        '''
        Sets a budget goal for the user.
        :param goal: The budget goal amount.
        '''
        if goal < 0:
            raise ValueError("Budget goal cannot be negative.")
        self.budget_goal = goal