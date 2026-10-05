def add_task(self, task):
        if isinstance(task, Task):
            self.tasks.append(task)