def remove_dependency(self, task_id):
        if task_id in self.dependencies:
            self.dependencies.remove(task_id)