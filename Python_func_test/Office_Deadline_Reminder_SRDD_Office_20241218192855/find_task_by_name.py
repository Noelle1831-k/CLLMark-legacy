def find_task_by_name(self, name):
        for task in self.tasks:
            if task.name == name:
                return task
        return None