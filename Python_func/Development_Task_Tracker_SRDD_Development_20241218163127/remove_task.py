def remove_task(self, task_id):
        if task_id in self.tasks:
            self.tasks.remove(task_id)