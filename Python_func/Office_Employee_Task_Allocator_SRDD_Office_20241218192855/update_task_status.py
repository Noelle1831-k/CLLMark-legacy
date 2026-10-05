def update_task_status(self, task_id, status):
        '''
        Updates the status of a specific task.
        '''
        task = next((t for t in self.tasks if t.id == task_id), None)
        if task:
            task.status = status