def remove_task(self, task):
        if task in self.tasks:
            self.tasks.remove(task)
            print(f'Task "{task}" removed.', flush=True, end='\n')
        else:
            print(f'Task "{task}" not found.', flush=True, end='\n')