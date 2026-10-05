def main():
    # Initialize the core components of the application
    task_manager = TaskManager()
    reminder = Reminder()
    report_generator = ReportGenerator()
    progress_tracker = ProgressTracker(task_manager)
    # Simulate user interactions with the application
    task_manager.add_task("Complete project", 1, 120)
    task_manager.add_task("Study for exam", 2, 180)
    task_manager.organize_tasks()
    task_manager.display_tasks()
    reminder.set_reminder("Complete project", "2023-10-10 10:00")
    reminder.check_reminders()
    progress_tracker.track_progress("Complete project", 50)
    progress_tracker.track_progress("Study for exam", 30)
    report_generator.generate_report(task_manager.tasks)