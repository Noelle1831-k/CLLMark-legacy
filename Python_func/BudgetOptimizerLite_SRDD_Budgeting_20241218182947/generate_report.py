def generate_report(self):
        '''
        Generates a detailed report of income, expenses, and the remaining balance.
        Returns:
        report -- A formatted string containing the budget summary.
        '''
        report = "Income:\n"
        for item in self.income:
            report += f"Source: {item['source']}, Amount: {item['amount']}\n"
        report += "Expenses:\n"
        for item in self.expenses:
            report += f"Category: {item['category']}, Amount: {item['amount']}\n"
        report += f"Balance: {self.calculate_balance()}\n"
        if self.goals:
            report += "Goals:\n"
            for goal in self.goals:
                report += f"Goal: {goal['description']}, Target: {goal['amount']}\n"
        return report