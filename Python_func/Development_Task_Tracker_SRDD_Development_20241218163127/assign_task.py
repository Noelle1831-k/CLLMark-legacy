def assign_task(self, task_id):
        if task_id not in self.assigned_tasks:
            self.assigned_tasks.append(task_id)