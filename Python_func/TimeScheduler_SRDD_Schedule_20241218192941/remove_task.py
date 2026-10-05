def remove_task(self, name):
        if name in self.tasks:
            del self.tasks[name]
            print(f"Task '{name}' removed.")
        else:
            print(f"Task '{name}' not found.")