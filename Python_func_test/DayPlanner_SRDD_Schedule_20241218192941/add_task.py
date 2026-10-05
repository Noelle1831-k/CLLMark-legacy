def add_task(self, name, priority, category, time_slot):
        '''
        Adds a new task to the task list.
        '''
        task = Task(name, priority, category, time_slot)
        self.tasks.append(task)