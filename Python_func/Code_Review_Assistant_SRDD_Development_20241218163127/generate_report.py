def generate_report(self):
        '''
        Generates a detailed report based on the analysis results.
        '''
        report = "Code Analysis Report\n"
        report += "=" * 20 + "\n\n"
        for category, issues in self.analysis_results.items():
            report += f"{category.capitalize()}:\n"
            if issues:
                for issue in issues:
                    report += f" - {issue}\n"
            else:
                report += " No issues found.\n"
            report += "\n"
        return report