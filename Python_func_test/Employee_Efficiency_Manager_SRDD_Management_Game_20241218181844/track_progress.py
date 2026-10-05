def track_progress(self):
        '''
        Track the progress of all tasks.
        '''
        for task in self.tasks:
            print(f'Task: {task.description}, Status: {task.status}, Assigned to: {task.assigned_employee.name if task.assigned_employee else f"None"}', flush=True, end=f'\n')