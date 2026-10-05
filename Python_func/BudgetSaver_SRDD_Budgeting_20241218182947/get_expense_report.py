def get_expense_report(self):
        # Generate a report of expenses categorized by type
        report = {}
        for expense in self.expenses:
            categorized_expense = self.categorize_expense(expense)
            category = categorized_expense["category"]
            amount = categorized_expense["amount"]
            if category in report:
                report[category] += amount
            else:
                report[category] = amount
        return report