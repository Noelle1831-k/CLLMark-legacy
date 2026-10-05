def organize_tasks(self):
        '''
        Organizes tasks based on priority.
        '''
        self.tasks.sort(key=lambda x: x["priority"])