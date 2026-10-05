def main():
    budget_optimizer = BudgetOptimizer()
    # Adding incomes
    budget_optimizer.add_income("Salary", 5000)
    budget_optimizer.add_income("Freelance", 1500)
    # Adding expenses
    budget_optimizer.add_expense("Rent", 1200)
    budget_optimizer.add_expense("Groceries", 300)
    # Setting goals
    budget_optimizer.set_goal("Vacation", 2000)
    # Visualizing budget
    budget_optimizer.visualize_budget()
    # Tracking savings
    budget_optimizer.track_savings("Emergency Fund", 5000, 1500)
    budget_optimizer.track_savings("New Car", 10000, 3000)