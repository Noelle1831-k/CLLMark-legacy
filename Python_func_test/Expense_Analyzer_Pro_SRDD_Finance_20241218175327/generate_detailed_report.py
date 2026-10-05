def generate_detailed_report(self, expenses_by_category, budget):
        report = "Detailed Expense Report:\n"
        for category, amounts in expenses_by_category.items():
            total = sum(amounts)
            budget_amount = budget.get(category, 0)
            report += f"{category}: ${total} (Budget: ${budget_amount}, Difference: ${budget_amount - total})\n"
        return report