def main():
    '''
    Main function to initialize and run the application.
    '''
    data_storage = DataStorage()
    user_data = data_storage.load_data()
    habit_tracker = HabitTracker(user_data.get('habits', []))
    habit_monitor = HabitMonitor(user_data.get('activity_log', {}))
    recommendation_engine = RecommendationEngine()
    user_interface = UserInterface(habit_tracker, habit_monitor, recommendation_engine)
    while True:
        user_interface.display_menu()
        user_interface.handle_user_input()