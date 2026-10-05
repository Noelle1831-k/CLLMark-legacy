def generate_investment_report(self):
        report = 'Investments:\n'
        for name, details in self.investments.items():
            report += f'{name}: Amount: ${details["amount"]}, Growth: ${details["growth"]}\n'
        return report