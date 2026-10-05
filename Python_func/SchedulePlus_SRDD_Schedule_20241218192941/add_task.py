def add_task(self, name, priority, due_date):
        task = {
            'name': name,
            'priority': priority,
            'due_date': due_date,
            'status': 'Pending'
        }
        self.tasks.append(task)