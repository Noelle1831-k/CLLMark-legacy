def generate_report(self):
        '''
        Generates a report of all expenses.
        '''
        print("Generating report...")
        self.report_generator.generate_monthly_report(self.expenses)