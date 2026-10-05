def display_tasks(self):
        print("Tasks:")
        for task in self.task_manager.tasks:
            print(f"- {task}")