def load_tasks(self, tasks_data):
        '''
        Loads tasks from a given data source.
        Parameters:
        - tasks_data: A list of task data dictionaries.
        '''
        for task_data in tasks_data:
            task = Task(**task_data)
            self.add_task(task)