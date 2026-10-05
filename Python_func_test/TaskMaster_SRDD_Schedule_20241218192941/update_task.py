def update_task(self, name, **kwargs):
        for task in self.tasks:
            if task['name'] == name:
                for key, value in kwargs.items():
                    if key in task:
                        task[key] = value