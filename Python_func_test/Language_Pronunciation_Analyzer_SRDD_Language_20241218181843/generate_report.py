def generate_report(self):
        report = "Pronunciation Analysis Report\n"
        report += "=============================\n"
        report += f"Analysis Result: {self.analysis_result}\n"
        with open("report.txt", "w") as file:
            file.write(report)
        print("Report generated: report.txt")