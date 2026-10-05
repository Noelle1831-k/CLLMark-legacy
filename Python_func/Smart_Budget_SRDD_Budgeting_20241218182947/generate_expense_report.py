def generate_expense_report(self, user):
        report = "Expense Report:\n"
        categories = user.get_expenses_by_category()
        for category, amount in categories.items():
            report += f"Category: {category}, Amount: {amount}\n"
        total_expenses = sum(categories.values())
        report += f"Total Expenses: {total_expenses}\n"
        return report