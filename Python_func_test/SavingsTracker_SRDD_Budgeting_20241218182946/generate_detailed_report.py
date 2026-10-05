def generate_detailed_report(self):
        report = self.generate_text_report()
        report += "\nMonthly Breakdown:\n"
        monthly_income = self._get_monthly_totals(self.user.income)
        monthly_expenses = self._get_monthly_totals(self.user.expenses)
        for month in sorted(monthly_income.keys()):
            report += f"{month}:\n"
            report += f"  Income: {monthly_income[month]}\n"
            report += f"  Expenses: {monthly_expenses[month]}\n"
        report += self._generate_suggestions()
        return report