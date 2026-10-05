def track_progress(self):
        milestones = self.goal.get_milestones()
        for milestone in milestones:
            progress = random.randint(0, 100)
            self.progress_data.append((milestone, progress))
            print(f"Progress for {milestone}: {progress}%")