def organize_tasks(self):
        self.tasks.sort(key=lambda task: (task.priority, task.time_allocated))
        print("Tasks organized by priority and time allocated.")