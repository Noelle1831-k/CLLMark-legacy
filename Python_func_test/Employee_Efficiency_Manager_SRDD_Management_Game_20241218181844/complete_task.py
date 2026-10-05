def complete_task(self, task):
        '''
        Mark a task as completed and update performance.
        '''
        if task in self.tasks:
            task.status = "Completed"
            self.performance += 10
            self.tasks.remove(task)