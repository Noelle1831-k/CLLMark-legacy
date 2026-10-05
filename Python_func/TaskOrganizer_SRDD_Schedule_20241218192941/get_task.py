def get_task(self, task_title):
        for task in self.tasks:
            if task.title == task_title:
                return task
        return None