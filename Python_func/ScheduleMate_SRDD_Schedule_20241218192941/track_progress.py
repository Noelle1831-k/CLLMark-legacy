def track_progress(self, schedule):
        progress = {}
        for task in schedule.tasks:
            progress[task.name] = task.status
        return progress