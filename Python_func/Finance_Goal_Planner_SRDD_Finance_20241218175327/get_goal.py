def get_goal(self, name):
        '''
        Returns the goal details for a given goal name.
        '''
        return self.goals.get(name, None)