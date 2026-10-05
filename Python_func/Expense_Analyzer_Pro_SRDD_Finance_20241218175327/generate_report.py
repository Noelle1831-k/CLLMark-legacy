def generate_report(self, expenses_by_category):
        report = "Expense Report:\n"
        for category, amounts in expenses_by_category.items():
            total = sum(amounts)
            report += f"{category}: ${total}\n"
        return report