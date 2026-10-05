def update_task(self, task_id, title=None, description=None, deadline=None, priority=None):
        '''
        Updates the details of an existing task.
        '''
        task = self.tasks[task_id]
        task.update_details(title, description, deadline, priority)