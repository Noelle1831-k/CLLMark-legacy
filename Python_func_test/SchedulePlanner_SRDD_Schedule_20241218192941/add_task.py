def add_task(self, name, priority, due_date):
        task = Task(name, priority, due_date)
        self.tasks.append(task)