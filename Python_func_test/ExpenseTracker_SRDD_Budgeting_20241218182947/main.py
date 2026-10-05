def main():
    # Initialize components
    tracker = ExpenseTracker()
    dashboard = Dashboard()
    file_handler = FileHandler()
    # Load existing expenses from file
    expenses = file_handler.load_from_file('expenses.txt')
    tracker.load_expenses(expenses)
    # Add some sample expenses
    tracker.add_expense('2023-10-01', 'Food', 15.99, 'Lunch')
    tracker.add_expense('2023-10-02', 'Transport', 7.50, 'Bus fare')
    # Display expenses and summary
    dashboard.display_expenses(tracker.get_expenses())
    dashboard.display_summary(tracker.get_expenses())
    # Save expenses back to file
    file_handler.save_to_file(tracker.get_expenses(), 'expenses.txt')