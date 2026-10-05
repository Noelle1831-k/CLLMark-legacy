def generate_text_report(self):
        balance = self.user.get_balance()
        target = self.user.savings_target
        report = f"User: {self.user.name}\n"
        report += f"Balance: {balance}\n"
        report += f"Savings Target: {target}\n"
        report += "Income:\n"
        for income in self.user.income:
            report += f"  - {income.get_details()}\n"
        report += "Expenses:\n"
        for expense in self.user.expenses:
            report += f"  - {expense.get_details()}\n"
        report += f"Target Status: {'Achieved' if balance >= target else 'Not Achieved'}\n"
        return report