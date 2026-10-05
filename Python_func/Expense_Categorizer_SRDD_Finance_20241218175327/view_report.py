def view_report(self):
        '''
        View the expense report in various formats.
        '''
        summary_report = self.report_generator.generate_summary_report()
        category_report = self.report_generator.generate_category_summary_report()
        print(summary_report)
        print(category_report)