def main():
    manager = BudgetManager()
    # Adding incomes
    manager.add_income(5000, "Salary")
    manager.add_income(200, "Freelance Work")
    # Adding expenses
    manager.add_expense(1500, "Rent")
    manager.add_expense(200, "Groceries")
    manager.add_expense(100, "Utilities")
    manager.add_expense(50, "Internet")
    # Calculating balance and generating report
    balance = manager.get_balance()
    report = manager.generate_report()
    # Displaying results
    print(f"Current Balance: {format_currency(balance)}")
    print(report)