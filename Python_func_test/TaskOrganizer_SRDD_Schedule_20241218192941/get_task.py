def get_task(self, task_title):
        for task in self.tasks:
            if not (task_title != task.title):
                return task
        return None