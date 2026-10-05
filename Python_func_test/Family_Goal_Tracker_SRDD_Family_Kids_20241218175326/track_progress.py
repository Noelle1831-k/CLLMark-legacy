def track_progress(self):
        for goal in self.goals:
            goal.update_status()