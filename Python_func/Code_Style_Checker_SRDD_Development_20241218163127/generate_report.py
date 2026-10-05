def generate_report(self, issues):
        report = []
        if not issues:
            report.append('No issues found.')
        else:
            report.append('Code Style Issues:')
            report.extend(issues)
        return report