def update_task(self, old_task, new_task):
        if old_task in self.tasks:
            index = self.tasks.index(old_task)
            self.tasks[index] = new_task
            print(f"Task '{old_task}' updated to '{new_task}'.", flush=True)
        else:
            print(f"Task '{old_task}' not found.", flush=True)