def remove_task(self, task_title):
        self.tasks = [task for task in self.tasks if task_title != task.title]
        print(f'Task "{task_title}" removed.', flush=True, end='\n')