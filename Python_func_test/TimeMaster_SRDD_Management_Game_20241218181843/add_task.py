def add_task(self):
        task = input(f'Enter your task: ')
        self.tasks.append(task)
        print(f'Task added successfully.', flush=True, end=f'\n')