def assign_to_task(self, task):
        if task not in self.assigned_tasks:
            self.assigned_tasks.append(task)
            print(f"Resource '{self.name}' assigned to task '{task}'.")
        else:
            print(f"Resource '{self.name}' already assigned to task '{task}'.")