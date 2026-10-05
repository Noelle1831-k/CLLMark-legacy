def main():
    scheduler = Scheduler()
    time_manager = TimeManager()
    focus_manager = FocusManager()
    utils = Utils()
    # Example usage
    task1 = Task("Meeting", "Project meeting", "2023-10-01 10:00", "2023-10-01 11:00", "High")
    task2 = Task("Workout", "Gym session", "2023-10-01 12:00", "2023-10-01 13:00", "Medium")
    task3 = Task("Lunch", "Lunch with team", "2023-10-01 11:30", "2023-10-01 12:30", "Low")
    scheduler.add_task(task1)
    scheduler.add_task(task2)
    scheduler.add_task(task3)  # This should trigger an overlap warning
    scheduler.list_tasks()
    focus_manager.set_reminder(task1, "2023-10-01 09:50")
    focus_manager.start_focus_session(task1)