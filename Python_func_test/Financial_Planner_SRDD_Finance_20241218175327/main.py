def main():
    # Initialize user
    user1 = user.User("john_doe", "password123")
    # Budget management
    budget1 = budget.Budget(user1)
    budget1.add_income(5000, "Salary")
    budget1.add_expense(1500, "Rent")
    budget1.add_expense(200, "Groceries")
    budget1.add_expense(100, "Utilities")
    budget1.add_expense(50, "Internet")
    print(budget1.get_balance())
    print(budget1.generate_report())
    # Goal setting
    goal1 = goal.Goal(user1)
    goal1.set_goal("Vacation", 2000, "2024-12-31")
    goal1.set_goal("Emergency Fund", 5000, "2025-06-30")
    print(goal1.track_goal("Vacation"))
    goal1.update_goal("Vacation", 500)
    goal1.update_goal("Emergency Fund", 1000)
    print(goal1.track_goal("Emergency Fund"))
    # Investment planning
    investment1 = investment.Investment(user1)
    investment1.add_investment("Stocks", 1000)
    investment1.add_investment("Bonds", 500)
    investment1.add_investment("Real Estate", 2000)
    print(investment1.track_investment("Stocks"))
    print(investment1.track_investment("Bonds"))
    print(investment1.track_investment("Real Estate"))
    print(investment1.generate_investment_report())
    # Visualization
    visualization1 = visualization.Visualization(user1)
    data = {"Rent": 1500, "Groceries": 200, "Utilities": 100, "Internet": 50, "Savings": 3150}
    visualization1.generate_pie_chart(data)
    visualization1.generate_bar_chart(data)
    visualization1.generate_line_chart(data)
    # Educational resources
    education1 = education.Education()
    print(education1.get_tips())
    print(education1.get_resources())