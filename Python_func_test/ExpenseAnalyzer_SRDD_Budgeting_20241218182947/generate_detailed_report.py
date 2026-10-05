def generate_detailed_report(self, data):
        '''
        Generates a detailed textual report for the given categorized expense data.
        Parameters:
        data (dict): A dictionary containing categories as keys and amounts as values.
        Returns:
        str: A formatted string representing the detailed report.
        '''
        report = "Detailed Expense Report:\n"
        report += "-" * 30 + "\n"
        total_expense = 0
        for category, amount in data.items():
            report += f"Category: {category}\n"
            report += f"Amount: ${amount:.2f}\n"
            report += "-" * 30 + "\n"
            total_expense += amount
        report += f"Total Expense: ${total_expense:.2f}\n"
        report += "=" * 30 + "\n"
        return report