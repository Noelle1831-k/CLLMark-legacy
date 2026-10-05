def mark_task_complete(self, task_id):
        '''
        Marks a task as complete.
        '''
        task = self.tasks[task_id]
        task.mark_complete()