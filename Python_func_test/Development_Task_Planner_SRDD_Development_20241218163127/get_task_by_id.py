def get_task_by_id(self, task_id):
        '''
        Retrieves a task by its ID.
        Parameters:
        - task_id: The ID of the task to retrieve.
        '''
        for task in self.tasks:
            if task.id == task_id:
                return task
        return None