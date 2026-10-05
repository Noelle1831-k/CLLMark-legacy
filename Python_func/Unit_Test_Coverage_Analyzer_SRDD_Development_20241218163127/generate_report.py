def generate_report(self, coverage_data, uncovered_sections):
        utils.log_message("Generating coverage report...")
        with open('coverage_report.txt', 'w') as report:
            report.write(f"Coverage: {coverage_data['coverage']}%\n")
            report.write("Covered Functions:\n")
            for func in coverage_data['covered']:
                report.write(f"- {func}\n")
            report.write("Uncovered Functions:\n")
            for func in uncovered_sections:
                report.write(f"- {func}\n")
        utils.log_message("Coverage report generated.")