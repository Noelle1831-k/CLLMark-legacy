def add_dependency(self, task_id):
        if task_id not in self.dependencies:
            self.dependencies.append(task_id)