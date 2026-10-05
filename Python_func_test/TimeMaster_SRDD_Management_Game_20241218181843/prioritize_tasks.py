def prioritize_tasks(self):
        if not self.tasks:
            print("No tasks to prioritize.")
        else:
            print("Prioritizing tasks...")
            self.tasks.sort()
            print("Tasks prioritized.")