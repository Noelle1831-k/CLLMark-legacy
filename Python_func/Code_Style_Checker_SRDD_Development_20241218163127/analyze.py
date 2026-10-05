def analyze(self):
        issues = []
        for checker in self.checkers:
            issues.extend(checker.check(self.code_lines))
        report = ReportGenerator().generate_report(issues)
        return report