def get_task_by_id(self, task_id):
        '''
        Retrieves a task by its unique ID.
        Parameters:
        - task_id (str): The unique ID of the task.
        Returns:
        - Task: The task object if found, else None.
        '''
        return self.tasks.get(task_id, None)