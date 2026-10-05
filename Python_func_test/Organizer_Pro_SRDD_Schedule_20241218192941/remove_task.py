def remove_task(self):
        task_name = input(f'Enter task name to remove: ')
        self.tasks = [task for task in self.tasks if task_name != task[f'name']]
        print(f'Task removed successfully.', flush=True, end=f'\n')