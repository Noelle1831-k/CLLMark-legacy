def remove_task(self, task_id):
        '''
        Removes a task from the project based on its ID.
        Parameters:
        - task_id: The ID of the task to remove.
        '''
        self.tasks = [task for task in self.tasks if task.id != task_id]