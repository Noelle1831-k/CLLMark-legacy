def remove_task(self, name):
        self.tasks = [task for task in self.tasks if task["name"] != name]