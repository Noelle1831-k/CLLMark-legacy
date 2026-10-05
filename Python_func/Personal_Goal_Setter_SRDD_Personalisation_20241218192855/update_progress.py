def update_progress(self, goal_id, progress_update):
        '''
        Updates the progress of a specific goal.
        '''
        if goal_id in self.progress:
            self.progress[goal_id].append(progress_update)
        else:
            self.progress[goal_id] = [progress_update]