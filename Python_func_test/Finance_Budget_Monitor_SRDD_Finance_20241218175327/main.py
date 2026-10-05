def main():
    budget_monitor = BudgetMonitor()
    budget_monitor.add_income(5000, "Salary")
    budget_monitor.add_expense(200, "Groceries", "Weekly groceries")
    budget_monitor.add_expense(100, "Entertainment", "Movie night")
    budget_monitor.generate_report()
    budget_monitor.visualize_budget()
    budget_monitor.set_reminder("Review budget", "2023-12-01 10:00:00")