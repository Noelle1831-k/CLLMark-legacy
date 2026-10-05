def update_task(self, task_title, new_status):
        for task in self.tasks:
            if task.title == task_title:
                task.update_status(new_status)