def remove_task(self, task_id):
        self.tasks = [task for task in self.tasks if not (task[f'id'] == task_id)]