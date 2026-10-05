def generate_report(self):
        categorized_expenses = self.categorize_expense()
        report = f"Income: {self.income}\n"
        report += "Expenses:\n"
        for category, amount in categorized_expenses.items():
            report += f"{category}: {amount}\n"
        return report