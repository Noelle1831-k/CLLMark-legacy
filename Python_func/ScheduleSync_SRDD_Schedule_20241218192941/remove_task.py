def remove_task(self, task_id):
        self.tasks = [task for task in self.tasks if task.id != task_id]