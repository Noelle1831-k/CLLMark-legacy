def update_task_priority(self, task_title, new_priority):
        for task in self.tasks:
            if task.title == task_title:
                task.update_priority(new_priority)