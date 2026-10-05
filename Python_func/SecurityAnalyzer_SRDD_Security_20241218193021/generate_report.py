def generate_report(self):
        report = utilities.format_report(self.results)
        utilities.save_report(report)
        print(report)