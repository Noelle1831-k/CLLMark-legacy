def main():
    expense_manager = ExpenseManager()
    budget_manager = BudgetManager(expense_manager)
    visualization_manager = VisualizationManager()
    reminder_manager = ReminderManager()
    database_manager = DatabaseManager()
    # Example usage
    expense_manager.add_expense('food', 20.5, '2023-10-01')
    expense_manager.add_expense('transportation', 15.0, '2023-10-02')
    budget_manager.set_budget('food', 200)
    budget_manager.set_budget('transportation', 100)
    visualization_manager.generate_pie_chart(expense_manager.get_expenses_summary())
    reminder_manager.set_reminder('2023-10-10', 'Pay electricity bill')
    database_manager.save_data(expense_manager.get_all_expenses())