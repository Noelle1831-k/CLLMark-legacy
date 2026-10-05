def generate_report(self):
        self.report_generator.generate_summary(self.expenses)
        self.report_generator.generate_detailed_report(self.expenses)