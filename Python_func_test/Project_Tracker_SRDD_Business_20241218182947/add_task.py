def add_task(self, project_name, title, assignee, deadline):
        if self.database.project_exists(project_name):
            task = Task(title, assignee, deadline)
            self.database.save_task(project_name, task)
            print(f'Task "{title}" added to project "{project_name}".', flush=True, end='\n')
        else:
            print(f'Project "{project_name}" does not exist.', flush=True, end='\n')