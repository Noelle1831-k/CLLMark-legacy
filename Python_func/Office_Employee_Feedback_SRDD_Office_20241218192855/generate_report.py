def generate_report(self, analysis):
        report = "Feedback Analysis Report\n"
        report += f"Positive Feedback: {analysis['Positive']}\n"
        report += f"Negative Feedback: {analysis['Negative']}\n"
        report += f"Neutral Feedback: {analysis['Neutral']}\n"
        return report