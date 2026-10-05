def main():
    data_storage = DataStorage()
    expenses = data_storage.load_data()
    expense_tracker = ExpenseTracker(expenses)
    recommendation_engine = RecommendationEngine(expense_tracker)
    user_interface = UserInterface(expense_tracker, recommendation_engine, data_storage)
    user_interface.display_menu()