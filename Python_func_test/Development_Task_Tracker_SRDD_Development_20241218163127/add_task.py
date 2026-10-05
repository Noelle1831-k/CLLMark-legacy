def add_task(self, task_id):
        if task_id not in self.tasks:
            self.tasks.append(task_id)