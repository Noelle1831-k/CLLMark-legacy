def main():
    # Initialize user with name and income
    user = User("John Doe", 5000)
    # Initialize the expense tracker, recommendation engine, and savings goal
    expense_tracker = ExpenseTracker()
    recommendation_engine = RecommendationEngine()
    savings_goal = SavingsGoal(1000)
    # Add expenses to the expense tracker
    expense_tracker.add_expense("Groceries", 200)
    expense_tracker.add_expense("Utilities", 150)
    expense_tracker.add_expense("Entertainment", 100)
    # Update user's financial data with new expenses
    user.update_financial_data(new_expenses=expense_tracker.expenses)
    # Generate and print the expense report
    expense_report = expense_tracker.get_expense_report()
    print("Expense Report:", expense_report)
    # Generate and print recommendations based on the expense report
    recommendations = recommendation_engine.generate_recommendations(expense_report)
    print("Recommendations:", recommendations)
    # Set a new savings goal and track progress
    savings_goal.set_goal(2000)
    progress = savings_goal.track_progress(user)
    print("Savings Progress:", progress)