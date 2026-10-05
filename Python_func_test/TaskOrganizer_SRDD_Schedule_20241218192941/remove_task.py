def remove_task(self, task_title):
        self.tasks = [task for task in self.tasks if not (task_title == task.title)]