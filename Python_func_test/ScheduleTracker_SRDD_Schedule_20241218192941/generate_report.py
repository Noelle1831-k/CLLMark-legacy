def generate_report(self):
        print("Generating productivity report...")
        report_data = self._compile_report_data()
        self._display_report(report_data)