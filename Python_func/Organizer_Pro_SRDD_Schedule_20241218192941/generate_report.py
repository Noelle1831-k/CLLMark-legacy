def generate_report(self):
        print("Generating report...")
        if not self.task_manager.tasks:
            print("No tasks available to generate report.")
            return
        df = pd.DataFrame(self.task_manager.tasks)
        report_file = 'task_report.csv'
        df.to_csv(report_file, index=False)
        print(f"Report generated successfully and saved to {report_file}.")