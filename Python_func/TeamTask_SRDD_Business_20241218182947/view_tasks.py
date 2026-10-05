def view_tasks(self):
        for task in self.tasks:
            print(f"Task: {task.title}, Status: {task.status}")