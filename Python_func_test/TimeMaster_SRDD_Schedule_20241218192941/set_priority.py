def set_priority(self, task_name, priority):
        '''
        Sets the priority of a task.
        '''
        for task in self.tasks:
            if task_name == task[f'name']:
                task[f'priority'] = priority
                break