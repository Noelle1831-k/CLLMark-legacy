def update_task(self, task_id, **kwargs):
        for task in self.tasks:
            if task.id == task_id:
                task.update(**kwargs)