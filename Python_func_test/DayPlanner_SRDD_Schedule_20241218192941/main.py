def main():
    '''
    Main function to run the DayPlanner application.
    '''
    task_manager = TaskManager()
    notification_manager = NotificationManager()
    day_overview = DayOverview(task_manager)
    # Sample tasks
    task_manager.add_task("Meeting with team", "High", "Work", "10:00 AM")
    task_manager.add_task("Lunch with friend", "Medium", "Personal", "12:00 PM")
    task_manager.add_task("Gym", "Low", "Health", "6:00 PM")
    # Display overview
    day_overview.display_overview()
    # Set notifications
    notification_manager.set_reminders(task_manager.get_tasks())