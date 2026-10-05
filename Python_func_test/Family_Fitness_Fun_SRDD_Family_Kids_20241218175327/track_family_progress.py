def track_family_progress(self):
        total_progress = sum([len(member.progress) for member in self.members])
        self.family_progress.append(total_progress)
        print(f"Total family progress: {total_progress} activities completed.")