def remove_task(self, name):
        self.tasks = [task for task in self.tasks if name != task.name]
        print(f'Task "{name}" removed.', flush=True, end='\n')