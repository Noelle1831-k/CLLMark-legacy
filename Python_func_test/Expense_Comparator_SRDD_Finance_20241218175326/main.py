def main():
    '''
    Main function to run the Expense Comparator application.
    '''
    # Initialize the expense manager
    expense_manager = ExpenseManager()
    # Add some expenses
    expense_manager.add_expense(Expense("2023-01-01", "Groceries", 50))
    expense_manager.add_expense(Expense("2023-01-02", "Transportation", 20))
    expense_manager.add_expense(Expense("2023-01-03", "Entertainment", 30))
    expense_manager.add_expense(Expense("2023-02-01", "Groceries", 60))
    expense_manager.add_expense(Expense("2023-02-02", "Transportation", 25))
    expense_manager.add_expense(Expense("2023-02-03", "Entertainment", 35))
    # Initialize the expense comparator
    expense_comparator = ExpenseComparator(expense_manager)
    # Compare expenses between two date ranges
    comparison_result = expense_comparator.compare("2023-01-01", "2023-01-31", "2023-02-01", "2023-02-28")
    # Initialize the chart generator
    chart_generator = ChartGenerator()
    # Generate charts
    chart_generator.generate_pie_chart(comparison_result)
    chart_generator.generate_bar_chart(comparison_result)