def generate_report(self):
        report = Report(self.incomes, self.expenses)
        report.generate()