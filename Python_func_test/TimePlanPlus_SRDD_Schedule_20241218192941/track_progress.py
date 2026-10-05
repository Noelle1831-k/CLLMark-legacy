def track_progress(self, name):
        if name in self.tasks:
            progress = self.tasks[name]['progress']
            print(f"Task '{name}' is {progress}% complete.")
        else:
            print(f"Task '{name}' not found.")