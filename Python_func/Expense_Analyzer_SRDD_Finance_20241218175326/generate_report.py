def generate_report(self):
        '''
        Generate a detailed report of expenses and compare with the budget.
        '''
        report_generator = ReportGenerator(self.expenses)
        report_generator.generate_category_report()
        report_generator.compare_with_budget(self.budget)  # Use the dynamic budget