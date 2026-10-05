def main():
    # Initialize the ExpenseAnalyzer with a dynamic budget
    analyzer = ExpenseAnalyzer(budget=200)
    # Adding expenses with different categories
    analyzer.add_expense(50, 'groceries')
    analyzer.add_expense(20, 'entertainment')
    analyzer.add_expense(100, 'utilities')
    # Generate reports, visualize expenses, and provide tips
    analyzer.generate_report()
    analyzer.visualize_expenses()
    analyzer.provide_tips()