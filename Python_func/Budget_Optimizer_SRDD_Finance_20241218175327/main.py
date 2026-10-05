def main():
    # Create a user with sample data and financial goals
    user = User(
        "John Doe", 
        5000, 
        {"Rent": 1200, "Groceries": 600, "Utilities": 300, "Entertainment": 400},
        {"Rent": 30, "Groceries": 15, "Utilities": 10, "Entertainment": 10, "Savings": 35}
    )
    # Initialize the budget optimizer with the user
    optimizer = BudgetOptimizer(user)
    # Analyze expenses and generate recommendations
    optimizer.analyze_expenses()
    recommendations = optimizer.recommend_budget()
    # Generate a report
    report_generator = ReportGenerator(optimizer)
    report = report_generator.generate_report()
    # Print the report
    print(report)