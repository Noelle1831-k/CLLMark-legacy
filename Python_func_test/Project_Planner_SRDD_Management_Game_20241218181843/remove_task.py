def remove_task(self, task_name):
        if task_name in self.tasks:
            del self.tasks[task_name]
            print(f'Task "{task_name}" removed from project "{self.name}".', flush=True, end='\n')
        else:
            print(f'Task "{task_name}" not found in project "{self.name}".', flush=True, end='\n')