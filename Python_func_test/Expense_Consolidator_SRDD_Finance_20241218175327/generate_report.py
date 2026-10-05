def generate_report(expenses):
    # Simulate report generation
    print("Generating report...")
    total_expense = sum(expense.amount for expense in expenses)
    print(f"Total Expenses: {format_currency(total_expense)}")
    for expense in expenses:
        print(f"Report: {format_currency(expense.amount)} in {expense.category}")