def update_task(self, name, **kwargs):
        '''
        Updates task details.
        '''
        for task in self.tasks:
            if task.name == name:
                task.update(**kwargs)