def update_task(self, task_id, **kwargs):
        for task in self.tasks:
            if task_id == task.id:
                task.update(**kwargs)