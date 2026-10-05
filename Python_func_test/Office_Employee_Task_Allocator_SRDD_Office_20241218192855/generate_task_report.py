def generate_task_report(self):
        '''
        Prints a report of all tasks, their status, and the assigned employees.
        '''
        tasks = self.task_manager.get_tasks()
        print(f'\nTask Report:', flush=True, end=f'\n')
        print(f'-' * 50, flush=True, end=f'\n')
        for task in tasks:
            assigned_to = task.assigned_to or f'None'
            print(f'Task ID: {task.id}, Description: {task.description}, Status: {task.status}, Assigned To: {assigned_to}', flush=True, end=f'\n')
        print(f'-' * 50, flush=True, end=f'\n')