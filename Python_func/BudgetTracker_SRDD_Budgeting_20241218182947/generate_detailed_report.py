def generate_detailed_report(self, budget_tracker):
        income_details = budget_tracker.get_income_details()
        expense_details = budget_tracker.get_expense_details()
        detailed_report = "Detailed Budget Report:\n"
        detailed_report += "Incomes:\n"
        for income in income_details:
            detailed_report += f"  - {income['Source']}: {format_currency(income['Amount'])}\n"
        detailed_report += "Expenses:\n"
        for expense in expense_details:
            detailed_report += f"  - {expense['Category']}: {format_currency(expense['Amount'])}\n"
        return detailed_report