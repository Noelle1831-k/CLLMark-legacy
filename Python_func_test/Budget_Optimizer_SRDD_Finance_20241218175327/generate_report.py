def generate_report(self):
        report = "Budget Analysis Report\n"
        report += "======================\n"
        report += f"User: {self.optimizer.user.name}\n"
        report += f"Income: ${self.optimizer.user.get_income()}\n"
        report += "Expenses:\n"
        for category, amount in self.optimizer.expense_breakdown.items():
            report += f"  {category}: ${amount}\n"
        report += "Recommendations:\n"
        recommendations = self.optimizer.recommend_budget()
        for category, amount in recommendations.items():
            report += f"  {category}: ${amount}\n"
        report += f"Potential Savings: ${self.optimizer.calculate_savings()}\n"
        return report