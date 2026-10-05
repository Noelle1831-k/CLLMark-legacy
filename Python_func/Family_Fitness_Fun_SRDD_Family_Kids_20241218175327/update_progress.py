def update_progress(self, activity, duration):
        self.progress.append((activity, duration))
        print(f"{self.username} completed {activity.name} for {duration} minutes.")