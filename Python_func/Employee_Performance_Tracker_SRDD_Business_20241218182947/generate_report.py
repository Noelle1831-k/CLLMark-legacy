def generate_report(self, report):
        if isinstance(report, PerformanceReport):
            self.reports.append(report)