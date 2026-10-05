def generate_report(self):
        '''
        Generates a report of expenses by category.
        '''
        report = {}
        for expense in self.expenses:
            if expense.category not in report:
                report[expense.category] = 0
            report[expense.category] += expense.amount
        for category, total in report.items():
            print(f"Category: {category}, Total: {total}")