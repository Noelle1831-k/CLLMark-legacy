def track_progress(self, task_name, progress):
        if task_name in self.schedule:
            print(f"Tracking progress for {task_name}: {progress}%")