def set_goal(self, amount, description):
        '''
        Sets a financial goal in the budget.
        Arguments:
        amount -- The target goal amount.
        description -- A brief description of the goal.
        '''
        self.goals.append({'amount': amount, 'description': description})