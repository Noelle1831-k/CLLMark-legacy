def main():
    tracker = ExpenseTracker()
    visualizer = Visualization()
    reminder = Reminder()
    # Add some expenses
    tracker.add_expense('Groceries', 150, '2023-10-01')
    tracker.add_expense('Transportation', 50, '2023-10-02')
    tracker.add_expense('Entertainment', 100, '2023-10-03')
    # Set budgets
    tracker.set_budget('Groceries', 200)
    tracker.set_budget('Transportation', 100)
    # Generate report
    tracker.generate_report()
    # Check budgets
    tracker.check_budget()
    # Visualize expenses
    visualizer.plot_expenses(tracker.expenses)
    # Set reminders
    reminder.set_reminder('2023-10-05', 'Review your monthly budget!', 'monthly')
    reminder.set_reminder('2023-10-06', 'Pay credit card bill!', 'weekly')
    # Check reminders
    reminder.check_reminders()
    # Delete a reminder
    reminder.delete_reminder(0)
    # Check reminders again
    reminder.check_reminders()