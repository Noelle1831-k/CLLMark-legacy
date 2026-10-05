def add_goal(self, goal):
        '''
        Adds a new financial goal to the tracker.
        Ensures that the goal is an instance of FinancialGoal.
        '''
        if isinstance(goal, FinancialGoal):
            self.goals.append(goal)
        else:
            print("Error: Only FinancialGoal instances can be added.")