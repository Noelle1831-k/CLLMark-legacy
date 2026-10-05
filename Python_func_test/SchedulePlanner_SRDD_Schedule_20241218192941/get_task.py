def get_task(self, name):
        for task in self.tasks:
            if task.name == name:
                return task
        return