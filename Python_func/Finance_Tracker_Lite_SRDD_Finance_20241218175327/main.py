def main():
    tracker = FinanceTracker()
    # Sample data for demonstration
    tracker.add_income(1000, 'Salary', '2023-10-01')
    tracker.add_income(200, 'Freelance', '2023-10-05')
    tracker.add_expense(200, 'Food', '2023-10-02')
    tracker.add_expense(50, 'Transportation', '2023-10-03')
    tracker.add_expense(100, 'Entertainment', '2023-10-04')
    tracker.add_expense(150, 'Utilities', '2023-10-05')
    # Setting a budget
    tracker.set_budget(1500, {'Food': 300, 'Transportation': 100, 'Entertainment': 200, 'Utilities': 150})
    # Generating report
    tracker.generate_report()
    # Visualizing data
    tracker.visualize_data()
    # Checking budget status
    tracker.check_budget()