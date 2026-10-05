def generate_detailed_report(self):
        '''
        Generate a detailed report with priority counts, overdue tasks, and average completion time.
        '''
        report = "Detailed Task Analysis Report:\n"
        report += "=================================\n"
        # Priority breakdown
        report += "Priority Breakdown:\n"
        for priority, count in self.analysis.items():
            report += f"- {priority} priority tasks: {count}\n"
        # Overdue tasks
        if self.overdue_tasks:
            report += "\nOverdue Tasks:\n"
            for task in self.overdue_tasks:
                report += f"- {task}\n"
        else:
            report += "\nNo overdue tasks.\n"
        # Average completion time
        if self.completion_times:
            total_time = sum(entry["TimeTaken"] for entry in self.completion_times)
            avg_time = total_time / len(self.completion_times)
            report += f"\nAverage Completion Time: {avg_time:.2f} days\n"
        else:
            report += "\nNo task completion data available.\n"
        return report