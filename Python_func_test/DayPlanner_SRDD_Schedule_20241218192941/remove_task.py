def remove_task(self, name):
        '''
        Removes a task by name.
        '''
        self.tasks = [task for task in self.tasks if not (name == task.name)]