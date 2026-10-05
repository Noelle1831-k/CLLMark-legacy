def generate_savings_report(self):
        """
        Generates a text-based savings report.
        """
        income = self.db_handler.get_total_income()
        expenses = self.db_handler.get_total_expenses()
        target = self.db_handler.get_savings_target()
        savings = income - expenses
        progress = ((savings / target) * 100) if target > 0 else 0
        report = f"""
        Total Income: {income}
        Total Expenses: {expenses}
        Savings: {savings}
        Savings Target: {target}
        Progress: {progress:.2f}%
        """
        return report