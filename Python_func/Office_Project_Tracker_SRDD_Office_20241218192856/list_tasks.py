def list_tasks(self):
        if not self.tasks:
            print("No tasks available.")
        else:
            for idx, task in enumerate(self.tasks, start=1):
                print(f"{idx}. {task['name']} - {task['description']} (Status: {task['status']})")