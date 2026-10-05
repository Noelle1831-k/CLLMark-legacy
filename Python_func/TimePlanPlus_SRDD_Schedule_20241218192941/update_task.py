def update_task(self, name, deadline=None, progress=None):
        if name in self.tasks:
            if deadline:
                self.tasks[name]['deadline'] = deadline
            if progress is not None:
                self.tasks[name]['progress'] = progress
            print(f"Task '{name}' updated.")
        else:
            print(f"Task '{name}' not found.")