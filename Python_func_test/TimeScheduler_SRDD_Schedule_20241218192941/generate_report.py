def generate_report(self):
        report = "Productivity Report:\n"
        report += "====================\n"
        for task in self.reports:
            report += f"Task: {task['name']}, Progress: {task['progress']}%\n"
        print(report)
        return report