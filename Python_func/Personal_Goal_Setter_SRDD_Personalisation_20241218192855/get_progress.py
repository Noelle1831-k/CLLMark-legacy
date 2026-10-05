def get_progress(self, goal_id):
        '''
        Returns the progress of a specific goal.
        '''
        return self.progress.get(goal_id, [])