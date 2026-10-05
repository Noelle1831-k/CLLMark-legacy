def run_dashboard():
    print("Welcome to BudgetOptimizer Dashboard")
    income = income_tracker.IncomeTracker()
    expenses = expense_tracker.ExpenseTracker()
    budget = budget_goal.BudgetGoal()
    analyzer = spending_analyzer.SpendingAnalyzer()
    report = report_generator.ReportGenerator()
    # User input for income
    try:
        income_amount = float(input("Enter your monthly income: "))
        income.add_income(income_amount)
    except ValueError:
        print("Invalid input. Please enter a numeric value for income.")
        return
    # User input for expenses
    while True:
        try:
            expense_amount = float(input("Enter an expense amount (or 0 to finish): "))
            if expense_amount == 0:
                break
            expense_category = input("Enter the expense category: ")
            expenses.add_expense(expense_amount, expense_category)
        except ValueError:
            print("Invalid input. Please enter a numeric value for expense.")
    # User input for budget goal
    try:
        budget_goal_amount = float(input("Enter your budget goal amount: "))
        budget.set_goal(budget_goal_amount)
    except ValueError:
        print("Invalid input. Please enter a numeric value for budget goal.")
        return
    # Analyze spending and generate reports
    analyzer.analyze_spending(income, expenses)
    report.generate_report(income, expenses, budget)
    report.generate_charts(income, expenses)