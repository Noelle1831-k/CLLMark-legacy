def remove_task(self, task):
        '''
        Remove a task from the schedule.
        '''
        if task in self.schedule:
            self.schedule.remove(task)