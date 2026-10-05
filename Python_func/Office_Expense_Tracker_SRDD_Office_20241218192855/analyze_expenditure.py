def analyze_expenditure(self):
        self.expenditure_analyzer.identify_trends(self.expenses)
        self.expenditure_analyzer.suggest_savings(self.expenses)