def remove_task(self, task_title):
        self.tasks = [task for task in self.tasks if task.title != task_title]