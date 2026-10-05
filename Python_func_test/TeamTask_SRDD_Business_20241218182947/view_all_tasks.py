def view_all_tasks(self):
        for task in self.tasks:
            print(f'Task: {task.title}, Assignee: {task.assignee.name}, Status: {task.status}', end='\n')