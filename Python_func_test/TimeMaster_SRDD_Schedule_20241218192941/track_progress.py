def track_progress(self, task_name, progress):
        '''
        Tracks the progress of tasks.
        '''
        for task in self.tasks:
            if task["name"] == task_name:
                task["progress"] = progress
                break