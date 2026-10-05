def add_task(self, title, description, deadline, priority):
        '''
        Adds a new task to the task list.
        '''
        task = Task(title, description, deadline, priority)
        self.tasks.append(task)
        self.reminder.add_reminder(task)