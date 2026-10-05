def update_progress(self, task_name, progress):
        self.progress[task_name] = progress
        print(f"Progress for '{task_name}' updated to {progress}%.")