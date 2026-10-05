def update_task(self, task, new_task):
        '''
        Updates a task in the schedule.
        '''
        index = self.tasks.index(task)
        self.tasks[index] = new_task