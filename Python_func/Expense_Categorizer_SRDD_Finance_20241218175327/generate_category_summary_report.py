def generate_category_summary_report(self):
        '''
        Generate a summary report for each category.
        '''
        category_totals = {}
        for expense in self.data_storage.expenses:
            if expense.category in category_totals:
                category_totals[expense.category] += expense.amount
            else:
                category_totals[expense.category] = expense.amount
        report = "Category Summary Report:\n"
        for category, total in category_totals.items():
            report += f"{category}: {total}\n"
        return report