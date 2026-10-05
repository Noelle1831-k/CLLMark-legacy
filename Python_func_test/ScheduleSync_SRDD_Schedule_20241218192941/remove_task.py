def remove_task(self, task_id):
        self.tasks = [task for task in self.tasks if not (task.id == task_id)]