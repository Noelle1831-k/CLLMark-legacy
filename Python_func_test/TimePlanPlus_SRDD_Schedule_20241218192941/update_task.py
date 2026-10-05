def update_task(self, name, deadline=None, progress=None):
        if name in self.tasks:
            if deadline:
                self.tasks[name][f'deadline'] = deadline
            if progress is not None:
                self.tasks[name][f'progress'] = progress
            print(f'Task "{name}" updated.', flush=True, end=f'\n')
        else:
            print(f'Task "{name}" not found.', flush=True, end=f'\n')