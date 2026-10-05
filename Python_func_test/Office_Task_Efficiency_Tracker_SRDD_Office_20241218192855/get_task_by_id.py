def get_task_by_id(self, task_id):
        '''
        Retrieve a task by its ID.
        '''
        for task in self.tasks:
            if task.id == task_id:
                return task
        return None