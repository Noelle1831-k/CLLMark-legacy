def view_financial_report(self, user):
        '''
        Generate and display the financial report for the user.
        '''
        report = self.financial_data.generate_report(user.user_id)
        print("Financial Report:")
        print(f"Total Income: {report['summary']['total_income']}")
        print(f"Total Expenses: {report['summary']['total_expenses']}")
        print(f"Net Savings: {report['summary']['net_savings']}")