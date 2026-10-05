def generate_report(self):
        report_generator = ReportGenerator(self.incomes, self.expenses)
        return report_generator.generate()