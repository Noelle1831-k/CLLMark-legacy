def delete_task(self, name):
        if name in self.tasks:
            del self.tasks[name]
            print(f"Task '{name}' deleted.")
        else:
            print(f"Task '{name}' not found.")