def generate_report(self):
        for category_name, cat in self.categories.items():
            print(f"Category: {category_name}")
            for exp in cat.expenses:
                print(f"  - {exp.date}: ${exp.amount}")
        total = sum(exp.amount for exp in self.expenses)
        print(f"Total Expenses: ${total}")
        budget_manager = budget.Budget(500.0)
        budget_manager.compare_with_budget(total)
        # Generate visualization using the Report class
        report_generator = report.Report()
        report_generator.generate_visualization(self.expenses)