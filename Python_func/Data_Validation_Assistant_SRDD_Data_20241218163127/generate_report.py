def generate_report(self, validation_results):
        report = "Validation Report\n"
        report += "=" * 20 + "\n"
        for rule, errors in validation_results.items():
            report += f"Rule: {rule}\n"
            if errors:
                for column, error in errors.items():
                    report += f"Column: {column}, Error: {error}\n"
            else:
                report += "No errors found.\n"
            report += "-" * 20 + "\n"
        self.highlight_errors(report)