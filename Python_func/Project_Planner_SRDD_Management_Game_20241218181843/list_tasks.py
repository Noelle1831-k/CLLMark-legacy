def list_tasks(self):
        if self.tasks:
            print(f"Tasks in project '{self.name}':")
            for task_name in self.tasks:
                print(f"- {task_name}")
        else:
            print(f"No tasks in project '{self.name}'.")