def delete_task(self, task_id):
        '''
        Deletes a task from the task dictionary.
        Parameters:
        - task_id (str): The unique ID of the task to be deleted.
        '''
        if task_id in self.tasks:
            del self.tasks[task_id]