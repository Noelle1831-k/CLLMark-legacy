def add_task(self, name, due_date, priority):
        task = {
            'name': name,
            'due_date': due_date,
            'priority': priority,
            'completed': False
        }
        self.tasks.append(task)