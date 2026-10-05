def main():
    manager = expense_manager.ExpenseManager()
    manager.add_expense("Groceries", 50.0, "2023-10-01")
    manager.add_expense("Transportation", 20.0, "2023-10-02")
    manager.add_expense("Entertainment", 30.0, "2023-10-03")
    manager.generate_report()
    reminder_manager = reminder.Reminder()
    reminder_manager.set_reminder("2023-10-05", "Check your budget!")
    reminder_manager.check_reminders()