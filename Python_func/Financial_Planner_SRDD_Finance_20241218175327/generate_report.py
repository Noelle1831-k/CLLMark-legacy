def generate_report(self):
        report = "Income:\n"
        for item in self.income:
            report += f"{item['source']}: ${item['amount']}\n"
        report += "Expenses:\n"
        for item in self.expenses:
            report += f"{item['category']}: ${item['amount']}\n"
        report += f"Balance: ${self.get_balance()}\n"
        if self.savings_goal:
            report += f"Savings Goal: ${self.savings_goal}\n"
        return report