def generate_report(self):
        """
        Generates and displays a savings report.
        """
        try:
            report = self.report_generator.generate_savings_report()
            print("\n=== Savings Report ===")
            print(report)
        except Exception as e:
            print(f"An error occurred while generating the report: {e}")