def main():
    planner = BudgetPlanner()
    planner.load_data("budget_data.json")
    # Adding incomes
    planner.add_income("Salary", 5000)
    planner.add_income("Freelance", 1200)
    # Adding expenses
    planner.add_expense("Rent", 1500, "Housing")
    planner.add_expense("Groceries", 300, "Food")
    planner.add_expense("Utilities", 200, "Utilities")
    planner.add_expense("Dining Out", 150, "Food")
    # Generating reports
    report = planner.generate_report()
    print(report.generate_summary())
    print(report.generate_detailed_report())
    print(report.generate_category_report("Food"))
    # Saving data
    planner.save_data("budget_data.json")