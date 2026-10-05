def generate_report(self):
        report = "Workout Progress Report:\n"
        for record in self.progress_records:
            report += f"Date: {record['date']}, Progress: {record['progress']}\n"
        return report