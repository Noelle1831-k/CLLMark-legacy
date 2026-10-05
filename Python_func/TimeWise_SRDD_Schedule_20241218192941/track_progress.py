def track_progress(self, task_name, progress):
        for task in self.task_manager.tasks:
            if task.name == task_name:
                task.update_status(progress)
                print(f"Updated progress for '{task_name}' to {progress}%.")
                break
        else:
            print(f"Task '{task_name}' not found.")