def add_task(self, task_name):
        if task_name not in self.tasks:
            self.tasks[task_name] = Task(task_name)
            print(f"Task '{task_name}' added to project '{self.name}'.")
        else:
            print(f"Task '{task_name}' already exists in project '{self.name}'.")