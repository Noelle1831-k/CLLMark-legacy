def remove_task(self):
        try:
            task_id = int(input(f'Enter task ID to remove: '))
            self.task_manager.remove_task(task_id)
        except ValueError:
            print(f'Invalid task ID. Please enter a numeric value.', flush=True, end=f'\n')