def remove_from_task(self, task):
        if task in self.assigned_tasks:
            self.assigned_tasks.remove(task)
            print(f"Resource '{self.name}' removed from task '{task}'.")
        else:
            print(f"Resource '{self.name}' not assigned to task '{task}'.")