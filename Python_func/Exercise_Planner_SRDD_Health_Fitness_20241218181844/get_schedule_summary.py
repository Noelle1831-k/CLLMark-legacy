def get_schedule_summary(self):
        summary = "Workout Schedule:\n"
        for day in self.schedule:
            summary += day + "\n"
        return summary