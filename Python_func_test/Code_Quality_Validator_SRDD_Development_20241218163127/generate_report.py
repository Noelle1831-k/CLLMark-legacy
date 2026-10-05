def generate_report(self):
        report = "Code Quality Analysis Report\n"
        report += "=" * 30 + "\n"
        if not self.issues:
            report += "No issues detected. Your code adheres to the best practices!\n"
        else:
            for issue in self.issues:
                report += f"- {issue}\n"
        report += "=" * 30 + "\n"
        report += "End of Report\n"
        return report