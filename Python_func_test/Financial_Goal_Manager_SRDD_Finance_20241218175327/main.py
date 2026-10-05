def main():
    goal_manager = GoalManager()
    progress_tracker = ProgressTracker(goal_manager)
    notification_manager = NotificationManager(goal_manager)
    financial_advisor = FinancialAdvisor(goal_manager)
    user_interface = UserInterface(goal_manager, progress_tracker, notification_manager, financial_advisor)
    user_interface.display_menu()