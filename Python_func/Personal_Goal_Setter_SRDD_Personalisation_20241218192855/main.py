def main():
    '''
    Initializes the application components and starts the user interface.
    '''
    goal_manager = GoalManager()
    recommendation_engine = RecommendationEngine()
    progress_tracker = ProgressTracker()
    notification_system = NotificationSystem()
    user_interface = UserInterface(goal_manager, recommendation_engine, progress_tracker, notification_system)
    user_interface.run()