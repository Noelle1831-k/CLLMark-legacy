def generate_report(self, analysis, suggestions):
        print("Expense Analysis Report")
        print("=======================")
        for category, total in analysis.items():
            print(f"{category}: ${total:.2f}")
        print("\nOptimization Suggestions")
        print("========================")
        for suggestion in suggestions:
            print(suggestion)