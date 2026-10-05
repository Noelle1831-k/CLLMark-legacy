def export_analysis(self, filename="task_analysis_report.txt"):
        '''
        Export the analysis report to a text file for further review.
        '''
        report = self.generate_detailed_report()
        try:
            with open(filename, "w") as file:
                file.write(report)
            print(f"Report successfully exported to {filename}")
        except IOError as e:
            print(f"Failed to export report: {e}")