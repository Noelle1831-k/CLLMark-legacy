def update_task(self, task_id, **kwargs):
        '''
        Updates the attributes of a task.
        Parameters:
        - task_id: The ID of the task to update.
        - kwargs: Key-value pairs of attributes to update.
        '''
        task = self.get_task_by_id(task_id)
        if task:
            for key, value in kwargs.items():
                setattr(task, key, value)