def generate_report(self):
        report = "Activity Report:\n"
        for activity, count in self.analysis_results.items():
            report += f"{activity}: {count}\n"
        return report