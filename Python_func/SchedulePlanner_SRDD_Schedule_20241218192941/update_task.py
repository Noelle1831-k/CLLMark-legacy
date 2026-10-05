def update_task(self, name, **kwargs):
        for task in self.tasks:
            if task.name == name:
                task.priority = kwargs.get('priority', task.priority)
                task.due_date = kwargs.get('due_date', task.due_date)
                task.completed = kwargs.get('completed', task.completed)