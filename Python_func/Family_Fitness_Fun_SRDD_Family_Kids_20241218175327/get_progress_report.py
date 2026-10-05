def get_progress_report(self):
        report = f"Progress report for {self.username}:\n"
        for activity, duration in self.progress:
            report += f"- {activity.name}: {duration} minutes\n"
        return report